#include "Pixio/CanvasFactory.h"
#include "Pixio/Windowing/SoftwareRender/SoftwareRenderWindow.h"
#include "Pixio/Windowing/OpenGL/OpenGLWindow.h"

IWindowSharedPtr CanvasFactory::createCanvas(CanvasType type, IApplication& app, const CanvasAttributes& attr)
{
    switch (type)
    {
    case CANVAS_TYPE_SOFTWARE:
        return IWindowSharedPtr(new SoftwareRenderWindow(app, attr));
    case CANVAS_TYPE_OPENGL:
        return IWindowSharedPtr(new OpenGLWindow(app, attr));
    default:
        return 0;
    }
}
