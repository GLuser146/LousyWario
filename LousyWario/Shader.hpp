#pragma once

#include "glad.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

struct Shader {
	GLuint program, vertex, fragment;
};

std::string ReadFile(char* path){
    std::fstream file(path);

    if (!file.is_open()) {
        std::cout << "\033[33m" << "WARNING: couldnt read " << "\033[32m" << path << "\033[0m";
        return "\0";
    }

    std::string line, text;

    while (std::getline(file, line)) {
        text += line + "\n";
    }

    return text;
}

void CompileShader(GLuint& shader, const std::string src) {
    char* srcC = (char*)malloc(sizeof(char) * (src.length() + 1));
    if (srcC) {
        strcpy(srcC, src.c_str());
    }
    
    glShaderSource(shader, 1, (const GLchar* const*)&srcC, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);

        std::cout << "\033[31m" << infoLog << "\n SRC: " << "\032[0m\n" << src << "\033[0m\n";
    }
}

Shader CreateShader(char* vertexPath, char* fragPath) {
    Shader shader;

    shader.program = glCreateProgram();
    shader.vertex = glCreateShader(GL_VERTEX_SHADER);
    shader.fragment = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexSRC = ReadFile(vertexPath);
    std::string fragSRC = ReadFile(fragPath);

    CompileShader(shader.vertex, vertexSRC);
    CompileShader(shader.fragment, fragSRC);

    glAttachShader(shader.program, shader.vertex);
    glAttachShader(shader.program, shader.fragment);
    glLinkProgram(shader.program);

    int success;
    glGetProgramiv(shader.program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shader.program, 512, 0, infoLog);
        std::cout << "\033[31m\n" << "WARNING: failed to link " << "\033[32m\n" << vertexSRC << "\031[31m\n" << " and " <<
            "\033[32m\n" << fragSRC << "\033[0m\n";
    }

    return shader;
}