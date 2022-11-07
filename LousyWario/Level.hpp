#pragma once

#include "glad.h"

#include <iostream>

#include "Object.hpp"
#include "Shader.hpp"

class Level {
public:
	Level() { std::cout << "\033[33m" << "WARNING: No level path provided" << "\033[0m\n"; }
	Level(char* path);
private:
	uint8_t** levelDat;
	InstancedObject object;
	Shader shader;
};