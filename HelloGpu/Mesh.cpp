#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::initialize(unsigned int id, const VertexBuffers& vertexBuffers)
{
	meshId = id;
	meshBuffers = vertexBuffers;

	for (int i = 0; i < vertexBuffers.size(); i++)
	{
		vboId.push_back(i);
		createGLBuffer(vboId.at(i), vertexBuffers.at(i).vertices);
		enableAndFormatAttribArray(vertexBuffers.at(i).componentsCount, GL_FLOAT, GL_FALSE, vertexBuffers.at(i).componentsCount * sizeof(float), (GLvoid*)(0));
	}
}

void Mesh::initialize(unsigned int id, const VertexBuffers& vertexBuffers, const IndexBuffer& indexBuffer)
{
	initialize(id, vertexBuffers);

	meshIndices = indexBuffer;
	createGLBuffer(indexId, indexBuffer);

}

void Mesh::createGLBuffer(unsigned int & bufferId, const Buffer dataBuf)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	GLsizeiptr size = dataBuf.size() * sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, size, dataBuf.data(), GL_STATIC_DRAW);
}

// overload to create GL_ELEMENT_ARRAY_BUFFER
void Mesh::createGLBuffer(unsigned int  & bufferId, const IndexBuffer dataBuf)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	GLsizeiptr size = dataBuf.size() * sizeof(unsigned int);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, dataBuf.data(), GL_STATIC_DRAW);
}

void Mesh::enableAndFormatAttribArray(int size, unsigned int type, bool normalized, int stride, const void * pointer)
{
	static GLuint attributeArrayIndex = 0;
	glEnableVertexAttribArray(attributeArrayIndex);
	glVertexAttribPointer(attributeArrayIndex, size, type, normalized, stride, pointer);

	attributeArrayIndex++;
}

void Mesh::rotate(const float angle, axis axis)
{
	if (x_axis == axis)
	{
		for each (BufferObject obj in meshBuffers)
		{
			if (BufferType::vertices == obj.type)
			{

			}
		}
	}
	else if (y_axis == axis)
	{
		//GLuint yAng = glGetUniformLocation(programId, "yAngle");
		//glUniform1f(yAng, angle);
	}
	else if (z_axis == axis)
	{
		//GLuint zAng = glGetUniformLocation(programId, "zAngle");
		//glUniform1f(zAng, angle);
	}
}

void Mesh::move()
{

}