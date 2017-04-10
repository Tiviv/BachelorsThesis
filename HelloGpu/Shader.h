#pragma once

class Shader
{
public:
	Shader(const char* vertexShaderFile, const char* fragmentShaderFile);
	void use();
	const unsigned int getProgramID() const;
private:
	//load, compile and link the shader program from files
	unsigned int load(const char* vertexShaderFile, const char* fragmentShaderFile);
	
	//programID of compiled program
	unsigned int programID;

};