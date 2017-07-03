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

	Buffer verticesValues{ 	
		-1.0f, -1.0f,
		1.0f, -1.0f,
		-1.0f,  1.0f,
		1.0f,  1.0f,
	};
	
	Buffer textureValues{ 	0.0f, 0.0f,

		0.0f,  1.0f,
		1.0f, 0.0f,
		1.0f,  1.0f,};

	BufferObject vertices = BufferObject(verticesValues, 2);
	vertices.type = BufferType::vertices;
	BufferObject texCoords = BufferObject(textureValues, 2);
	texCoords.type = BufferType::textureCoords;

	VertexBuffers meshData;
	meshData.push_back(vertices);
	meshData.push_back(texCoords);
	
	graphicsResManager.addMesh(1, meshData);
	
	Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/TeacherStudent.png");
	glEnable(GL_TEXTURE_2D);
	texture.Bind(0);
	// Change point size
	glPointSize(15);
	//draw antialiased point 
	glEnable(GL_POINT_SMOOTH);

	//Z-buffer
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_GEQUAL);
	//glClearDepth(-1.0);

	// Color buffer
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	//Culling
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Wireframe
	glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);

}

void HelloGpu::onDestroy()
{

}

void HelloGpu::onRender(float delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glDrawArrays(GL_TRIANGLE_STRIP, 0,4);
	
	//use single GL call to draw vbo points
	//glDrawElements(GL_TRIANGLES, 2, GL_UNSIGNED_BYTE, (GLvoid*)(0));
}

void HelloGpu::onMouseEvent(unsigned int x, unsigned int y, unsigned char button, unsigned char state, unsigned int modifiers)
{
	if(state == 0)
	stateMachine.goToNextState(x, y, attr.size.x, attr.size.y);
}

void HelloGpu::onKeyboardEvent(unsigned char c, unsigned char state, unsigned int modifiers)
{
	
}
