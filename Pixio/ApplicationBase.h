#pragma once

#include "Pixio/IApplication.h"

class ApplicationBase : public IApplication
{
public:
    ApplicationBase();
    virtual void onInit();
    virtual void onDestroy();
    virtual void onRender(float delta);
    virtual void onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers);
    virtual void onMouseMove(unsigned int x, unsigned int y, unsigned char state, unsigned int modifiers);
    virtual void onMouseScroll(unsigned int x, unsigned int y, int delta, unsigned char state, unsigned int modifiers);
    virtual void onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers);
protected:
    float time;
};