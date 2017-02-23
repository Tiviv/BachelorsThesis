#pragma once

class IWindow;

class IApplication
{
public:
    virtual ~IApplication() {}
    virtual void onInit()                                                                                                        = 0;
    virtual void onDestroy()                                                                                                     = 0;
    virtual void onRender(float delta)                                                                                           = 0;
    virtual void onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers) = 0;
    virtual void onMouseMove(unsigned int x, unsigned int y, unsigned char state, unsigned int modifiers)                        = 0;
    virtual void onMouseScroll(unsigned int x, unsigned int y, int delta, unsigned char state, unsigned int modifiers)           = 0;
    virtual void onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers)                                   = 0;
};