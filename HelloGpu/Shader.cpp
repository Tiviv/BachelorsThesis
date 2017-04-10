#include "Pixio/ShaderUtils/Shader.h"
#include "Shader.h"

Shader::Shader(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	programID = load(vertexShaderFile, fragmentShaderFile);
}

unsigned int Shader::load(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	return LoadShadersFromFile(vertexShaderFile, fragmentShaderFile);
}

void Shader::use()
{
	glUseProgram(programID);
}

const unsigned int Shader::getProgramID() const
{
	return programID;
}