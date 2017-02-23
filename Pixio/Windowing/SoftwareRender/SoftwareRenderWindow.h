#pragma once

#include "Pixio/IWindow.h"
#include "Pixio/IApplication.h"
#include "Pixio/CanvasAttributes.h"

#include <windows.h>

class SoftwareRenderWindow : public IWindow
{
public:
    SoftwareRenderWindow(IApplication& app, const CanvasAttributes& attr);
    ~SoftwareRenderWindow();

    virtual void           startRenderLoop();
    virtual unsigned char* getCurrentDrawBuffer();
    virtual void           drawPoint(const Vec2& position,
                                     unsigned char r, 
                                     unsigned char g, 
                                     unsigned char b);
    virtual void           clear(unsigned char r,
                                 unsigned char g,
                                 unsigned char b,
                                 unsigned char a);
    virtual unsigned int   getWidth()      const;
    virtual unsigned int   getHeight()     const;
    virtual unsigned int   getBufferSize() const;
private:
    static LRESULT CALLBACK onEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    IApplication&           app;
    const CanvasAttributes& attr;
    unsigned char*          drawBuffer;
    unsigned int            bufferSize;
    HDC                     hdcMem;
    HBITMAP                 hbmMem;
    int                     lastKey;
};

typedef std::shared_ptr<SoftwareRenderWindow> SoftwareRenderWindowSharedPtr;