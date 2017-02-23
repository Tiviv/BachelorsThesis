#include "ResourceManager.h"
#include "HelloGpu.h"
HelloGpu::HelloGpu(const CanvasAttributes & attr) : attr(attr), graphicsResManager()
{
}

HelloGpu::~HelloGpu()
{
}

void HelloGpu::onInit()
{

	glewInit();
	graphicsResManager.loadShader();

    GLuint positionLocation = glGetAttribLocation(graphicsResManager.getCurrentProgramId(), "vPosition");
	GLuint colorLocation = glGetAttribLocation(graphicsResManager.getCurrentProgramId(), "vColor");

	GLuint xAngle = glGetUniformLocation(graphicsResManager.getCurrentProgramId(), "xAngle");
	GLuint yAngle = glGetUniformLocation(graphicsResManager.getCurrentProgramId(), "yAngle");
	GLuint zAngle = glGetUniformLocation(graphicsResManager.getCurrentProgramId(), "zAngle");

    glUseProgram(graphicsResManager.getCurrentProgramId());

	dummyHelperAngle = 10.0f;

	graphicsResManager.loadGeometry(objectToRender);
	
	IndexBuffer index { 0, 3, 2, 0, 2, 1,   //front
					    4, 0, 1, 4, 1, 5,   //right
						7, 4, 5, 7, 5, 6,   //back
						3, 7, 6, 3, 6, 2,   //left
						4, 7, 3, 4, 3, 0,   //top
						1, 2, 6, 1, 6, 5, //bottom

						2, 3, 0, 1, 2, 0,   //front other
						1, 0, 4, 5, 1, 4,   //right other
						5, 4, 7, 6, 5, 7,   //back other
						6, 7, 3, 2, 6, 3,   //left other
						3, 7, 4, 0, 3, 4,   //top other
						6, 2, 1, 5, 6, 1 }; //bottom other

	Buffer tmp;
	for (Vec3Buffer::const_iterator itr = objectToRender.cbegin(), stop = objectToRender.cend();
		itr != stop;
		++itr)
	{
		tmp.push_back((*itr).x);
		tmp.push_back((*itr).y);
		tmp.push_back((*itr).z);
	}
	//call ResourceManager to send and format the coordinates
	graphicsResManager.createGLBuffer(graphicsResManager.vbIdPos, tmp);
	graphicsResManager.enableAndFormatAttribArray(3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(0));
	
	graphicsResManager.enableAndFormatAttribArray(3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));

	graphicsResManager.createGLBuffer(graphicsResManager.ibIdIndices, index);
	
	// Change point size
	glPointSize(15);
	//draw antialiased point 
	glEnable(GL_POINT_SMOOTH);

	//Z-buffer
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_GEQUAL);
	glClearDepth(-1.0);

	// Color buffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Culling
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	//Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Wireframe
	glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);

}

void HelloGpu::onDestroy()
{

}

void HelloGpu::onRender(float delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//use single GL call to draw vbo points
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, (GLvoid*)(0));
}

void HelloGpu::onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers)
{
	printf("OnMouseEvent \n");
	Buffer tmp;
	dummyHelperAngle += 0.005;

	graphicsResManager.rotateGeometry(objectToRender, dummyHelperAngle, x_axis);
	graphicsResManager.rotateGeometry(objectToRender, dummyHelperAngle, y_axis);

}

void HelloGpu::onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers)
{
	
}
