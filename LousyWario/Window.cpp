
#include <iostream>
#include <vector>
#include <functional>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"

Window window = Window();

Window::Window(char* title, int width, int height) {
	this->width = width;
	this->height = height;
	window = glfwCreateWindow(width, height, title, NULL, NULL);
}

void Window::Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < drawList.size(); i += 2) {
		drawList[i]();
	}

	glfwSwapBuffers(window);

}
void Window::AddToDrawList(std::function<void()> func) {
	drawList.push_back(func);
}