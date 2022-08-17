#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Takka
{
	class Window
	{
	public:

		Window(const Window&) = delete;
		Window(Window&& win) noexcept;

		Window& operator=(const Window&) = delete;
		Window& operator=(Window&& win) noexcept;

		Window(std::string title, GLint w, GLint h) noexcept;
		~Window() noexcept;

		void GetSize(GLuint& w, GLuint& h);
		GLFWwindow* GetWindow();

	private:
		GLint w = 0, h = 0;
		GLFWwindow* window = nullptr;
	};
}