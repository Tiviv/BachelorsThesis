#pragma once

#include "Pixio/IWindow.h"
#include "Pixio/IApplication.h"
#include "Pixio/CanvasAttributes.h"

enum CanvasType
{
    CANVAS_TYPE_SOFTWARE,
    CANVAS_TYPE_OPENGL
};

class CanvasFactory
{
public:
    static IWindowSharedPtr createCanvas(CanvasType type, IApplication& app, const CanvasAttributes& attr);
};