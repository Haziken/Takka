#include <Application.h>

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
	Setup();
	while(!glfwWindowShouldClose(win->GetWindow()))
	{
		glClearColor(0.5, 0.5, 0.5, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		Update();
		Render();
		
		glfwSwapBuffers(win->GetWindow());
	}
}
