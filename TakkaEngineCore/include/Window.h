#pragma once
#include "Utils.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Takka
{
	class Window
	{
	public:
		DELCPY(Window);
		Window(std::string title, GLint w, GLint h);
		~Window();

		void getSize(GLuint& w, GLuint& h);
	private:
		GLint w, h;
		GLFWwindow* window;
	};
}