#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <functional>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

class Window {
public:
	Window() { window = NULL; height = 0; width = 0; }
	Window(char* title, int width, int height);

	void Draw();
	void AddToDrawList(std::function<void()> func);


	int width, height;

	GLFWwindow* window;
private:

	std::vector<std::function<void()>> drawList;
};

extern Window window;