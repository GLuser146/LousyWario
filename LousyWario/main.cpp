#include <iostream>

#include "Initializer.hpp"
#include "GameManager.hpp"
#include "ImageLoader.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>

int main() {
	InitAPI();

	gameManager.MainLoop();

	return 0;
}