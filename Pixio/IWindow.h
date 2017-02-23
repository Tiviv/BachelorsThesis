#pragma once

#include "Math/Vector.h"
#include <memory>

class IWindow
{
public:
    virtual ~IWindow() {}

    virtual void           startRenderLoop()       = 0;
    virtual unsigned int   getWidth()        const = 0;
    virtual unsigned int   getHeight()       const = 0;
    virtual unsigned int   getBufferSize()   const = 0;
};

typedef std::shared_ptr<IWindow> IWindowSharedPtr;