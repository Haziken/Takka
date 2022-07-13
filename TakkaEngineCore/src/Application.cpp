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
	while(true)
	{
		Update();
		Render();
	}
}
