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
	graphicsResManager.addProgram();
	
	float side = 0.2f;
	float offset = 0.2f;
	Buffer verticesValues{ side , side, side,
						 side,-side, side,
						-side,-side, side,
						-side, side, side,
						 side, side,-side,
						 side,-side,-side,
						-side,-side,-side,
						-side, side,-side
	};
	
	Buffer colorValues{	0.5f, 0.5f, 0.5f,
		0.5f, 0.0f, 0.99f,
		0.99f, 0.6f, 0.7f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.0f, 0.99f,
		0.99f, 0.6f, 0.7f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.0f, 0.99f,
	};

	BufferObject vertices = BufferObject(verticesValues, 3);
	BufferObject colors = BufferObject(colorValues, 3);

	VertexBuffers meshData;
	meshData.push_back(vertices);
	meshData.push_back(colors);

	//dummyHelperAngle = 10.0f;
	GLuint xAng = glGetUniformLocation(graphicsResManager.getCurrentProgramId(), "xAngle");
	glUniform1f(xAng, 25.0f * PI / 180.0f);

	//graphicsResManager.loadGeometry(objectToRender);
	
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

	graphicsResManager.addMesh(1, meshData, index);
	//graphicsResManager.addMesh()
	
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
	glCullFace(GL_BACK);

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

	
	static float t = 0.0f;
	t += 0.0001;
	GLuint yAng = glGetUniformLocation(graphicsResManager.getCurrentProgramId(), "yAngle");
	GLuint offset = glGetUniformLocation(graphicsResManager.getCurrentProgramId(), "posOffset");

	glUniform1f(yAng, t * -195.0f * PI / 180.0f);
	glUniform3f(offset, 0.2f, 0.2f, 0.0f);
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, (GLvoid*)(0));

	glUniform1f(yAng, t * -50.0f * PI / 180.0f);
	glUniform3f(offset, -0.2f, -0.2f, 0.0f);
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, (GLvoid*)(0));

	glUniform1f(yAng, t * -100.0f * PI / 180.0f);
	glUniform3f(offset, -0.2f, 0.2f, 0.0f);
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, (GLvoid*)(0));

	
	//use single GL call to draw vbo points
	//glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, (GLvoid*)(0));
}

void HelloGpu::onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers)
{
	printf("OnMouseEvent \n");
	Buffer tmp;
	dummyHelperAngle += 0.005;
}

void HelloGpu::onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers)
{
	
}
