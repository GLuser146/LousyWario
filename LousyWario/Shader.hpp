#pragma once

#include "glad.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>

typedef struct Shader {
    GLuint program, vertex, fragment;
};

std::string ReadFile(char* path);

void CompileShader(GLuint& shader, const std::string src);

Shader CreateShader(char* vertexPath, char* fragPath);