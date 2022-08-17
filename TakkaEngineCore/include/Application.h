#pragma once

#include "Window.h"

#include <chrono>
#include <thread>
#include <iostream>

namespace Takka
{
    class Application
    {
    public:
        Application() = delete;
        Application(const Application& app) = delete;
        Application(Application&& app) noexcept;

        Application& operator=(const Application& app) = delete;
        Application& operator=(Application&& app) noexcept;

        Application(std::string title, GLuint w, GLuint h) noexcept;
        Application(Window* win) noexcept;

        ~Application() noexcept;

        Window* GetWindow();

        virtual void Setup() {};
        virtual void Update(float delta) {};
        virtual void Render() {};

        void Run();

    private:
        Window* win = nullptr;
    };
}