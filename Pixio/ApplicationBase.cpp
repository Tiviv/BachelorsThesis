#include "Pixio/ApplicationBase.h"
#include "Pixio/IWindow.h"
#include <iostream>

using namespace std;

ApplicationBase::ApplicationBase() : time(0.0f)
{
}

void ApplicationBase::onInit()
{

}

void ApplicationBase::onDestroy()
{

}

void ApplicationBase::onRender(float delta)
{
    time += delta;
}

void ApplicationBase::onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers)
{
    cout << "onMouseEvent [ " << x << ", " << y << ", " << int(button) << ", " << int(state) << ", " << modifiers << " ]" << endl;
}

void ApplicationBase::onMouseMove(unsigned int x, unsigned int y, unsigned char state, unsigned int modifiers)
{
    if (modifiers)
    {
        cout << "onMouseMove [ " << x << ", " << y << ", " << int(state) << ", " << modifiers << " ]" << endl;
    }
}

void ApplicationBase::onMouseScroll(unsigned int x, unsigned int y, int delta, unsigned char state, unsigned int modifiers)
{
    cout << "onMouseScroll [ " << x << ", " << y << ", " << delta << ", " << int(state) << ", " << modifiers << " ]" << endl;
}

void ApplicationBase::onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers)
{
    cout << "onKeyboardEvent [ " << c << ", " << int(state) << ", " << modifiers << " ]" << endl;
}
