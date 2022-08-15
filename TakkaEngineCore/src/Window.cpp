#include "../include/Window.h"

Takka::Window::Window(std::string title, GLint w, GLint h) : w(w), h(h)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}

Takka::Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Takka::Window::GetSize(GLuint& w, GLuint& h)
{
}

GLFWwindow* Takka::Window::GetWindow()
{
	return window;
}

