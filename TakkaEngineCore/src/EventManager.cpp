#include "../include/EventManager.h"

Takka::EventManager::EventManager() {}

Takka::EventManager* Takka::EventManager::instance()
{
    static EventManager* manager = new EventManager();
    return manager;
}

void Takka::EventManager::Init(GLFWwindow* window)
{
    this->window = window;
    glfwSetKeyCallback(window, EventManager::KeyboardEvent);
    glfwSetCharCallback(window, EventManager::TextEvent);
    glfwSetCursorPosCallback(window, EventManager::CursorMoveEvent);
    glfwSetCursorEnterCallback(window, EventManager::CursorEnterEvent);
    glfwSetScrollCallback(window, EventManager::ScrollEvent);
    glfwSetMouseButtonCallback(window, EventManager::MouseButtonEvent);
}

void Takka::EventManager::Registrate(Event* e)
{
    eventList.push_back(e);
}

void Takka::EventManager::Delete(Event* e)
{
    for (auto i = eventList.begin(); i != eventList.end(); ++i)
    {
        if (*i == e)
        {
            eventList.erase(i);
            break;
        }
    }
}

int Takka::EventManager::GetScancode(int key)
{
    return glfwGetKeyScancode(key);
}

int Takka::EventManager::GetState(int key)
{
    return glfwGetKey(window, key);
}

void Takka::EventManager::SetInputMode(int mode, int flag)
{
    glfwSetInputMode(window, mode, flag);
}

std::string Takka::EventManager::GetKeyName(int key)
{
    return std::string();
}

void Takka::EventManager::GetCursorPos(double& x, double& y)
{
}

int Takka::EventManager::GetButtonState(int key)
{
    return 0;
}

const float* Takka::EventManager::GetJoysticAxes(int stick, int& count)
{
    return nullptr;
}

const unsigned char* Takka::EventManager::GetJoysticButton(int stick, int& count)
{
    return nullptr;
}

const unsigned char* Takka::EventManager::GetJoysticHats(int stick, int& count)
{
    return nullptr;
}

std::string Takka::EventManager::GetJoysticName(int stick)
{
    return std::string();
}

std::string Takka::EventManager::GetGamepadName(int stick)
{
    return std::string();
}

bool Takka::EventManager::isGamepad(int stick)
{
    return false;
}

bool Takka::EventManager::GetGamepadState(int stick, GLFWgamepadstate& state)
{
    return false;
}

void Takka::EventManager::SetTime(float time)
{
}

uint64_t Takka::EventManager::GetTimeValue()
{
    return uint64_t();
}

uint64_t Takka::EventManager::GetTimeFrequency()
{
    return uint64_t();
}

std::string Takka::EventManager::GetClipboardString()
{
    return std::string();
}

void Takka::EventManager::SetClipboardString(std::string text)
{
}

// Main event

void Takka::EventManager::KeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    for (auto i : EVENTMANAGER->GetEventList())
    {
        if (action == GLFW_PRESS) i->KeyPress(key, mods);
        if (action == GLFW_RELEASE) i->KeyRelease(key, mods);
        if (action == GLFW_REPEAT) i->KeyRepeat(key, mods);
    }
}

void Takka::EventManager::TextEvent(GLFWwindow* window, unsigned int codepoint)
{
    for (auto i : EVENTMANAGER->GetEventList())
        i->TextInput(codepoint);
}

void Takka::EventManager::CursorMoveEvent(GLFWwindow* window, double xpos, double ypos)
{
    for (auto i : EVENTMANAGER->GetEventList())
        i->CursorPosition(xpos, ypos);
}

void Takka::EventManager::CursorEnterEvent(GLFWwindow* window, int entered)
{
    for (auto i : EVENTMANAGER->GetEventList())
        i->CursorEnder(entered);
}

void Takka::EventManager::MouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
{
    for (auto i : EVENTMANAGER->GetEventList())
    {
        if (action == GLFW_PRESS) i->MouseButtonPress(button, mods);
        if (action == GLFW_RELEASE) i->MouseButtonRelease(button, mods);
    }
}

void Takka::EventManager::ScrollEvent(GLFWwindow* window, double xoffset, double yoffset)
{
    for (auto i : EVENTMANAGER->GetEventList())
        i->Scroll(xoffset, yoffset);
}

std::vector<Takka::Event*>& Takka::EventManager::GetEventList()
{
    return eventList;
}
