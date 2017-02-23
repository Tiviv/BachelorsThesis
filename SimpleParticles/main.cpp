#include "ParticleApp.h"

int main()
{
    CanvasAttributes attr(Vec2(100.0f), Vec2(800.0f), "SimpleParticles");
    ParticlesApp app(attr);
    auto canvasPtr = CanvasFactory::createCanvas(CANVAS_TYPE_SOFTWARE, app, attr);
    app.setCanvas(std::static_pointer_cast<SoftwareRenderWindow>(canvasPtr));
    canvasPtr->startRenderLoop();
    return 0;
}