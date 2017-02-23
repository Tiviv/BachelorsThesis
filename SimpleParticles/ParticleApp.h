#pragma once

#include "Pixio/CanvasFactory.h"
#include "Pixio/ApplicationBase.h"
#include "Pixio/Windowing/SoftwareRender/SoftwareRenderWindow.h"

class ParticlesApp : public ApplicationBase
{
public:
    ParticlesApp(const CanvasAttributes& attr);
    ~ParticlesApp();
    virtual void onRender(float delta);
    void setCanvas(SoftwareRenderWindowSharedPtr canvas);

private:
    const CanvasAttributes&       attr;
    unsigned int*                 particlePositions;
    unsigned int                  particleCount;
    SoftwareRenderWindowSharedPtr canvas;
};