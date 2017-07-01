#version 330 core

in vec3 color;
in vec2 texture;
// Ouput data
layout(location = 0) out vec4 outColor;


//varying vec2 texCoord0;

uniform sampler2D diffuse;

void main()
{
	outColor = texture2D(diffuse, texture);
	
}