#pragma once

#include <GL/glew.h>

GLuint LoadShadersFromFile(const char * vertex_file_path, const char * fragment_file_path);
GLuint LoadShadersFromString(const char * vertex_source, const char * fragment_source);