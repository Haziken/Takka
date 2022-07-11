#include "Window.h"

Takka::Window::Window(std::string title, GLint w, GLint h) : w(w), h(h)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);
}

Takka::Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
