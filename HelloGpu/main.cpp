#include "Pixio/CanvasFactory.h"
#include "HelloGpu.h"

int main()
{
    CanvasAttributes attr(Vec2(100.0f), Vec2(800.0f), "HelloGpu");
    HelloGpu app(attr);
    auto canvasPtr = CanvasFactory::createCanvas(CANVAS_TYPE_OPENGL, app, attr);
    canvasPtr->startRenderLoop();
    return 0;
}