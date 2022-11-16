#pragma once

#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>

#include "Object.hpp"
#include "Shader.hpp"
#include "Window.hpp"
#include "InputManager.hpp"
#include "Level.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player {
public:
	Player();
	void Draw();

	void Movement();
	void Collision(std::vector<std::vector<Chunk>> chunks);

	Collider collider;
private:
	Object object;
	Shader shader;

	float sizeMultiplier;

	//MOVEMENT STUFF
	glm::vec2 dir = glm::vec2(0.0);

	float acc = 1;
	float deAcc = 0.1;
	float maxDirX = 10;

};