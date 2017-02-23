#pragma once

#include "Pixio/IWindow.h"
#include "Pixio/IApplication.h"
#include "Pixio/CanvasAttributes.h"

class OpenGLWindow : public IWindow
{
public:
    OpenGLWindow(IApplication& app, const CanvasAttributes& attr);
    ~OpenGLWindow();

    virtual void           startRenderLoop();
    virtual unsigned int   getWidth()      const;
    virtual unsigned int   getHeight()     const;
    virtual unsigned int   getBufferSize() const;
private:
    int window;
    void onRender();
    void onMouseEvent(int, int, int, int);
    void onKeyboardEvent(unsigned char, int, int);
    void onMouseMove(int x, int y);

    static bool init;
    static void render();
    static void mouseEvent(int, int, int, int);
    static void keyboardEvent(unsigned char, int, int);
    static void mouseMove(int, int);

    IApplication&           app;
    const CanvasAttributes& attr;
};

typedef std::shared_ptr<OpenGLWindow> OpenGLWindowSharedPtr;


