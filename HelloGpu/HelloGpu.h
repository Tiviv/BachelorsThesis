#pragma once
#include "Texture.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Pixio/CanvasFactory.h"
#include "Pixio/ApplicationBase.h"
#include <GL/glew.h>

class HelloGpu : public ApplicationBase
{
public:
    HelloGpu(const CanvasAttributes& attr);
    ~HelloGpu();
    virtual void onInit();
    virtual void onDestroy();
    virtual void onRender(float delta);
	virtual void onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers);
	virtual void onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers);

private:
    const CanvasAttributes& attr;

	float dummyHelperAngle;
	const float PI = 3.141592f;
	ResourceManager graphicsResManager;
	StateMachine stateMachine;

	
};

