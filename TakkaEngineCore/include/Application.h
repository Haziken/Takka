#pragma once

#include "Window.h"

#include <chrono>
#include <thread>

namespace Takka
{
    class Application
    {
    public:
        DELCPY(Application);
        Application() = delete;
        Application(std::string title, GLuint w, GLuint h);
        Application(Window* win);

        Window* GetWindow();

        virtual void Setup() {};
        virtual void Update(float delta) {};
        virtual void Render() {};

        void Run();

    private:
        Window* win = nullptr;
    };
}