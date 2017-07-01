#pragma once
#include <map>
#include "Mesh.h"

class ResourceManager
{
public: 
	ResourceManager();
	~ResourceManager();

	void addMesh(unsigned int id, const VertexBuffers& vertexBuffers);
	void addMesh(unsigned int id, const VertexBuffers& vertexBuffers, const IndexBuffer& indexBuffer);
	void removeMesh(unsigned int id);	

	bool getMesh(unsigned int id, Mesh &mesh);

	//Shader loadind and acess 
	void addProgram();
	unsigned int getCurrentProgramId();
	unsigned int getAttributeFromShader(std::string attr);
	unsigned int getUniformFromShader(std::string uniform);
	void setShaderAttribute(std::string attr, void* value);
	void setShaderUniform(std::string uniform, void* value);

private:

	
	GLuint currentProgramId;
	std::map<unsigned int, Mesh> meshes;
public:
	GLuint vbIdPos;
	GLuint ibIdIndices;


};
