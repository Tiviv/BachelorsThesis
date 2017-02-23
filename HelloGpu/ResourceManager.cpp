#include "ResourceManager.h"
#include "Pixio/ShaderUtils/Shader.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	glDeleteBuffers(1, &vbIdPos);
	glDeleteBuffers(1, &ibIdIndices);
	glDeleteProgram(programId);
}

// create GL_ARRAY_BUFFER
void ResourceManager::createGLBuffer( GLuint & bufferId, const Buffer dataBuf)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	GLsizeiptr size = dataBuf.size() * sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, size, dataBuf.data() , GL_STATIC_DRAW);
}

// overload to create GL_ELEMENT_ARRAY_BUFFER
void ResourceManager::createGLBuffer(GLuint & bufferId, const IndexBuffer dataBuf)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	GLsizeiptr size = dataBuf.size() * sizeof(unsigned int);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, dataBuf.data(), GL_STATIC_DRAW);
}

void ResourceManager::enableAndFormatAttribArray(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)
{
	static GLuint attributeArrayIndex = 0;
	glEnableVertexAttribArray(attributeArrayIndex);
	glVertexAttribPointer(attributeArrayIndex, size, type, normalized, stride, pointer);

	attributeArrayIndex++;
}

void ResourceManager::loadShader()
{
	programId = LoadShadersFromFile("Shaders/basic.vs", "Shaders/basic.fs");
}

void ResourceManager::loadGeometry(Vec3Buffer &objectToRender)
{
	float side = 1.0f;
	float offset = side / 2;

	objectToRender.push_back(Vec3(offset, offset, offset)); //index 0
	objectToRender.push_back(Vec3(0.5f, 0.5f, 0.5f));
	objectToRender.push_back(Vec3(offset, -offset, offset)); //index 1
	objectToRender.push_back(Vec3(0.5f, 0.0f, 0.99f));
	objectToRender.push_back(Vec3(-offset, -offset, offset)); //index 2
	objectToRender.push_back(Vec3(0.99f, 0.6f, 0.7f));
	objectToRender.push_back(Vec3(-offset, offset, offset)); //index 3
	objectToRender.push_back(Vec3(0.5f, 0.5f, 0.5f));
	objectToRender.push_back(Vec3(offset, offset, -offset)); //index 4
	objectToRender.push_back(Vec3(0.5f, 0.0f, 0.99f));
	objectToRender.push_back(Vec3(offset, -offset, -offset)); //index 5
	objectToRender.push_back(Vec3(0.99f, 0.6f, 0.7f));
	objectToRender.push_back(Vec3(-offset, -offset, -offset)); //index 6
	objectToRender.push_back(Vec3(0.5f, 0.5f, 0.5f));
	objectToRender.push_back(Vec3(-offset, offset, -offset)); //index 7
	objectToRender.push_back(Vec3(0.5f, 0.0f, 0.99f));

	rotateGeometry(objectToRender, -15.0f, x_axis);
	rotateGeometry(objectToRender, 25.0f, y_axis);

}

void ResourceManager::rotateGeometry(Vec3Buffer &objectToRender, const float angle, axis axis)
{
	if (x_axis == axis)
	{
		GLuint xAng = glGetUniformLocation(programId, "xAngle");
		glUniform1f(xAng, angle);
	}
	else if (y_axis == axis)
	{
		GLuint yAng = glGetUniformLocation(programId, "yAngle");
		glUniform1f(yAng, angle);
	}
	else if (z_axis == axis)
	{
		GLuint zAng = glGetUniformLocation(programId, "zAngle");
		glUniform1f(zAng, angle);
	}
}

GLuint ResourceManager::getCurrentProgramId()
{
	return this->programId;
}