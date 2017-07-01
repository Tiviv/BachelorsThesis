#pragma once

#include <vector>
#include <GL/glew.h>
#include "Math/Vec3.h"

typedef std::vector<Vec3> Vec3Buffer;
typedef std::vector<float> Buffer;

enum BufferType
{
	vertices,
	colors,
	textureCoords
};

struct BufferObject
{
	BufferObject(Buffer inpVertices, unsigned char componentsCnt) {
		componentsCount = componentsCnt;
		vertices = inpVertices;
	}
	unsigned char componentsCount;
	Buffer vertices;
	BufferType type;
};

typedef std::vector<BufferObject> VertexBuffers;
typedef std::vector<GLbyte> IndexBuffer;

enum axis
{
	x_axis,
	y_axis,
	z_axis
};

class Mesh
{
public: 
	Mesh();
	~Mesh();

	void initialize(unsigned int id, const VertexBuffers& vertexBuffers, const IndexBuffer& indexBuffer);
	void initialize(unsigned int id, const VertexBuffers& vertexBuffers);
	void rotate(const float angle, axis axis);
	void move();
private:
	std::vector<unsigned int> vboId;
	unsigned int indexId;
	unsigned int meshId;
	VertexBuffers meshBuffers;
	IndexBuffer meshIndices;

	void createGLBuffer(unsigned int & bufferId, const Buffer dataBuf);
	void createGLBuffer(unsigned int  & bufferId, const IndexBuffer dataBuf);
	void enableAndFormatAttribArray(int size, unsigned int type, bool normalized, int stride, const void * pointer);
};
