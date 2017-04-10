#include "ResourceManager.h"
#include "Shader.h"


ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	glDeleteBuffers(1, &vbIdPos);
	glDeleteBuffers(1, &ibIdIndices);
	glDeleteProgram(currentProgramId);
}


void ResourceManager::addMesh(unsigned int id, const VertexBuffers& vertexBuffers, const IndexBuffer& indexBuffer)
{
	Mesh newMesh;
	newMesh.initialize(id, vertexBuffers, indexBuffer);
	meshes.insert_or_assign(id, newMesh);

}
void ResourceManager::removeMesh(unsigned int id)
{
	meshes.erase(id);
}

bool ResourceManager::getMesh(unsigned int id, Mesh &mesh)
{
	bool result = false;

	std::map<unsigned int, Mesh>::iterator it = meshes.find(id);
	if (meshes.end() != it)
	{
		mesh = it->second;
		result = true;
	}

	return result;
}

void ResourceManager::addProgram()
{
	Shader newProgram = Shader("Shaders/basic.vs", "Shaders/basic.fs");
	currentProgramId = newProgram.getProgramID();
	newProgram.use();
}

//void ResourceManager::rotateGeometry(Vec3Buffer &objectToRender, const float angle, axis axis)
//{
//	if (x_axis == axis)
//	{
//		GLuint xAng = glGetUniformLocation(programId, "xAngle");
//		glUniform1f(xAng, angle);
//	}
//	else if (y_axis == axis)
//	{
//		GLuint yAng = glGetUniformLocation(programId, "yAngle");
//		glUniform1f(yAng, angle);
//	}
//	else if (z_axis == axis)
//	{
//		GLuint zAng = glGetUniformLocation(programId, "zAngle");
//		glUniform1f(zAng, angle);
//	}
//}

GLuint ResourceManager::getCurrentProgramId()
{
	return this->currentProgramId;
}

unsigned int ResourceManager::getAttributeFromShader(std::string attr)
{
	return -1;
}
unsigned int ResourceManager::getUniformFromShader(std::string uniform)
{
	return -1;
}
void ResourceManager::setShaderAttribute(std::string attr, void* value)
{

}
void ResourceManager::setShaderUniform(std::string uniform, void* value)
{

}