#pragma once

#include <iostream>
#include <functional>

#include "Object.hpp"
#include "Shader.hpp"
#include "Window.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player {
public:
	Player();
	std::function<void()> Draw();

	Collider collider;
private:
	Object object;
	Shader shader;

};