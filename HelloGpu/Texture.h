#pragma once
#include <string>

class Texture
{
public:
	Texture(const std::string& filename);
	virtual ~Texture();

	void Bind(unsigned int unit);

private:
	unsigned int textureID;
};

