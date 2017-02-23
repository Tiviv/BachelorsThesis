#include "Pixio/Windowing/SoftwareRender/SoftwareRenderWindow.h"
#include <windowsx.h>

SoftwareRenderWindow::SoftwareRenderWindow(IApplication & app, const CanvasAttributes & attr) :
    app(app),
    attr(attr),
    drawBuffer(0),
    bufferSize(static_cast<unsigned int>(attr.size.x) * 
               static_cast<unsigned int>(attr.size.y) * 4),
    hdcMem(0),
    hbmMem(0)
{
    drawBuffer = new unsigned char[bufferSize];
    memset(drawBuffer, 0, bufferSize);
}

SoftwareRenderWindow::~SoftwareRenderWindow()
{
    delete[] drawBuffer;
}

void SoftwareRenderWindow::startRenderLoop()
{
    HINSTANCE hInst = GetModuleHandle(NULL);

    WNDCLASSEX wcex = { 0 };

    wcex.cbSize        = sizeof(WNDCLASSEX);
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = onEvent;
    wcex.hInstance     = hInst;
    wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszClassName = "MainWindow";

    RegisterClassEx(&wcex);

    HWND hWnd = CreateWindowEx(NULL,
        "MainWindow",
        attr.name.c_str(),
        WS_OVERLAPPEDWINDOW,
        static_cast<int>(attr.position.x),
        static_cast<int>(attr.position.y),
        static_cast<int>(attr.size.x),
        static_cast<int>(attr.size.y),
        NULL,  // We have no parent window, NULL.
        NULL,  // We aren't using menus, NULL.
        hInst,
        NULL); // We aren't using multiple windows, NULL.

    SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG>(this));

    ShowWindow(hWnd, SW_SHOWNORMAL);

    MSG msg = { 0 };

    HDC hdc = GetDC(hWnd);

    bool stop = false;
    while (!stop)
    {
        // Process any messages in the queue.
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                stop = true;
                break;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        InvalidateRect(hWnd, 0, FALSE);
    }

    ReleaseDC(hWnd, hdc);
}

unsigned char * SoftwareRenderWindow::getCurrentDrawBuffer()
{
    return drawBuffer;
}

void SoftwareRenderWindow::drawPoint(const Vec2& position, unsigned char r, unsigned char g, unsigned char b)
{
    unsigned int row    = static_cast<unsigned int>(4 * attr.size.x * position.y);
    unsigned int offset = static_cast<unsigned int>(row + 4 * position.x);
    drawBuffer[offset + 0] = b;
    drawBuffer[offset + 1] = g;
    drawBuffer[offset + 2] = r;
}

void SoftwareRenderWindow::clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    for (unsigned int i = 0; i < bufferSize; i += 4)
    {
        drawBuffer[i + 0] = b;
        drawBuffer[i + 1] = g;
        drawBuffer[i + 2] = r;
        drawBuffer[i + 3] = a;
    }
}

unsigned int SoftwareRenderWindow::getWidth() const
{
    return static_cast<unsigned int>(attr.size.x);
}

unsigned int SoftwareRenderWindow::getHeight() const
{
    return static_cast<unsigned int>(attr.size.y);
}

unsigned int SoftwareRenderWindow::getBufferSize() const
{
    return bufferSize;
}

LRESULT SoftwareRenderWindow::onEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    SoftwareRenderWindow* canvas = reinterpret_cast<SoftwareRenderWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

    switch (message)
    {
    case WM_COMMAND:
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc;
        hdc = BeginPaint(hWnd, &ps);

        canvas->app.onRender(0.016f);

        auto& hdcMem    = canvas->hdcMem;
        auto& hbmMem    = canvas->hbmMem;
        auto width      = canvas->getWidth();
        auto height     = canvas->getWidth();
        auto bufferSize = canvas->getBufferSize();
        auto drawBuffer = canvas->getCurrentDrawBuffer();

        // Create an off-screen DC for double-buffering
        if (!hbmMem)
        {
            hdcMem = CreateCompatibleDC(hdc);
            hbmMem = CreateCompatibleBitmap(hdc, width, height);
        }

        // Draw back buffer
        HANDLE hOld = SelectObject(hdcMem, hbmMem);

        SetBitmapBits(hbmMem, bufferSize, drawBuffer);

        // Transfer the off-screen DC to the screen
        BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);

        // Free-up the off-screen DC
        SelectObject(hdcMem, hOld);

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    case WM_KEYUP:
    {
        canvas->app.onKeyboardEvent(canvas->lastKey, 0, 0);
        break;
    }
    case WM_CHAR:
    {
        canvas->app.onKeyboardEvent(wParam, 1, 0);
        canvas->lastKey = wParam;
        break;
    }
    case WM_LBUTTONDOWN:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseEvent(x, y, 0, 1, wParam);
        break;
    }
    case WM_LBUTTONUP:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseEvent(x, y, 0, 0, wParam);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseEvent(x, y, 1, 1, wParam);
        break;
    }
    case WM_RBUTTONUP:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseEvent(x, y, 1, 0, wParam);
        break;
    }
    case WM_MBUTTONDOWN:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseEvent(x, y, 2, 1, wParam);
        break;
    }
    case WM_MBUTTONUP:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseEvent(x, y, 2, 0, wParam);
        break;
    }
    case WM_MOUSEMOVE:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        canvas->app.onMouseMove(x, y, 0, wParam);
        break;
    }
    case WM_MOUSEWHEEL:
    {
        int x         = GET_X_LPARAM(lParam);
        int y         = GET_Y_LPARAM(lParam);
        int delta     = GET_WHEEL_DELTA_WPARAM(wParam);
        int modifiers = GET_KEYSTATE_WPARAM(wParam);
        canvas->app.onMouseScroll(x, y, delta, 0, modifiers);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
