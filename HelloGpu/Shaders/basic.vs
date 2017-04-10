#version 330 core

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
out vec3 color;

uniform float xAngle;
uniform float yAngle;
uniform float zAngle;
uniform vec3 posOffset;


void around_X_axis(inout vec3 point, in float angle)
{
	point = vec3(point.x,
				 point.y * cos(angle) - point.z * sin(angle),
				 point.y * sin(angle) + point.z * cos(angle));
}

void around_Y_axis(inout vec3 point, in float angle)
{
	point = vec3(point.x * cos(angle) + point.z * sin(angle),
				 point.y,
			    -point.x * sin(angle) + point.z * cos(angle));
}

void around_Z_axis(inout vec3 point, in float angle)
{
	point = vec3(point.x * cos(angle) - point.y * sin(angle),
				 point.x * sin(angle) + point.y * cos(angle),
				 point.z);
}

void main()
{
	color = vColor;

	vec3 tmp = vPosition;
	around_Y_axis(tmp, yAngle);
	around_X_axis(tmp, xAngle);

	tmp.x += posOffset.x;
	tmp.y += posOffset.y;
	tmp.z += posOffset.z;

    gl_Position = vec4(tmp, 0.5);
}

