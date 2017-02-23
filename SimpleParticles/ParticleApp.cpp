#include "..\HelloGpu\HelloGpu.h"
#include "..\HelloGpu\HelloGpu.h"
#include "ParticleApp.h"
#include <cmath>

ParticlesApp::ParticlesApp(const CanvasAttributes& attr) : ApplicationBase(), attr(attr), particleCount(0), canvas(0)
{
    unsigned int width  = static_cast<unsigned int>(attr.size.x);
    unsigned int height = static_cast<unsigned int>(attr.size.y);
    auto bufferSize     = width * height * 4;

    particleCount     = static_cast<unsigned int>(0.1f * width * height);
    particlePositions = new unsigned int[particleCount * 2];

    for (unsigned int i = 0; i < particleCount * 2; i += 2)
    {
        particlePositions[i + 0] = rand() % width;
        particlePositions[i + 1] = rand() % height;
    }
}

ParticlesApp::~ParticlesApp()
{
    delete[] particlePositions;
}

void ParticlesApp::onRender(float delta)
{
    ApplicationBase::onRender(delta);

    canvas->clear(0, 0, 0, 255);

    unsigned char r = static_cast<unsigned char>((sin(time) * 0.5f + 0.5f) * 100);
    unsigned char g = static_cast<unsigned char>((cos(time) * 0.5f + 0.5f) * 100);
    unsigned char b = r;

    for (unsigned int i = 0; i < particleCount * 2; i += 2)
    {
        auto& x = particlePositions[i + 0];
        auto& y = particlePositions[i + 1];

        canvas->drawPoint(Vec2(static_cast<float>(x), 
                              static_cast<float>(y)), 
                         r, g, b);
    }
}

void ParticlesApp::setCanvas(SoftwareRenderWindowSharedPtr canvas)
{
    this->canvas = canvas;
}
