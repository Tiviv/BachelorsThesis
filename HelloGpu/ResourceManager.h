#pragma once
#include <GL/glew.h>
#include <vector>
#include "Math/Vec3.h"

typedef std::vector<Vec3> Vec3Buffer;
typedef std::vector<float> Buffer;

struct VertexBuffer
{
	unsigned char componentsCount;
	Buffer vertices;
};

typedef std::vector<VertexBuffer> VertexBuffers;
typedef std::vector<GLbyte> IndexBuffer;

enum axis
{
	x_axis,
	y_axis,
	z_axis
};

class ResourceManager
{
public: 

	//void addMesh(unsigned int id, const VertexBuffers& vertexBuffers, const IndexBuffer& indexBuffer);
	//void removeMesh(unsigned int id);
	ResourceManager();
	~ResourceManager();

	void loadShader();
	void loadGeometry(Vec3Buffer &objectToRender);
	void rotateGeometry(Vec3Buffer &objectToRender,const float angle, axis axis);

	void createGLBuffer( GLuint & bufferId, const Buffer dataBuf);
	void createGLBuffer( GLuint & bufferId, const IndexBuffer dataBuf );

	void enableAndFormatAttribArray(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);

	GLuint getCurrentProgramId();
private:

	const float PI = 3.141592f;
	GLuint programId;

public:
	GLuint vbIdPos;
	GLuint ibIdIndices;


};
