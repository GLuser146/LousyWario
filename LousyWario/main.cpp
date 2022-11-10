#include <iostream>

#include "Initializer.hpp"
#include "GameManager.hpp"
#include "ImageLoader.hpp"
#include "Level.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>

int main() {
	InitAPI();

	GameManager gameManager;

	gameManager.MainLoop();

	return 0;
}