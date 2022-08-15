#include "../include/Application.h"
#include "../include/Logger.h"
Takka::Application::Application(std::string title, GLuint w, GLuint h)
{
	win = new Window(title, w, h);
}

Takka::Application::Application(Window* win) : win(win)
{}

Takka::Window* Takka::Application::GetWindow()
{
	return win;
}

void Takka::Application::Run()
{
	glEnable(GL_DEPTH_TEST);
	using namespace std::chrono_literals;
	Setup();
	auto delta = std::chrono::high_resolution_clock::now();
	while(!glfwWindowShouldClose(win->GetWindow()))
	{
		auto start = std::chrono::high_resolution_clock::now();
		glClearColor(0.5, 0.5, 0.5, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		std::chrono::duration<double, std::milli> deltaUpdate = std::chrono::high_resolution_clock::now() - delta;
		Update(deltaUpdate.count());
		delta = std::chrono::high_resolution_clock::now();
		Render();
		auto end = std::chrono::high_resolution_clock::now();
		glfwSwapBuffers(win->GetWindow());
		std::this_thread::sleep_for(16ms - (end - start));
	}
}
