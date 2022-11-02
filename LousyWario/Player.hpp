#pragma once

#include <iostream>

#include "Object.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player {
public:
	Player();
	Draw();
	Collider collider;
private:
	Object object;

};