#pragma once
#include "Event.h"
#include <GLFW/glfw3.h>
#include <vector>

#define EVENTMANAGER Takka::EventManager::instance()

#define REGEVENT EVENTMANAGER->Registrate(this);
#define DELEVENT EVENTMANAGER->Delete(this);

namespace Takka
{
	class EventManager final
	{
	public:
		static EventManager* instance();

		void Init(GLFWwindow* window);

		void Registrate(Event* e);
		void Delete(Event* e);

		int GetScancode(int key);
		int GetState(int key);

		void SetInputMode(int mode, int flag);

		std::string GetKeyName(int key);
		void GetCursorPos(double& x, double& y);

		int GetButtonState(int key);
		
		const float* GetJoysticAxes(int stick, int& count);
		const unsigned char* GetJoysticButton(int stick, int& count);
		const unsigned char* GetJoysticHats(int stick, int& count);
		std::string GetJoysticName(int stick);
		std::string GetGamepadName(int stick);
		bool isGamepad(int stick);
		bool GetGamepadState(int stick, GLFWgamepadstate& state);

		void SetTime(float time);
		uint64_t GetTimeValue();
		uint64_t GetTimeFrequency();

		std::string GetClipboardString();
		void SetClipboardString(std::string text);

		void GetWindowSize(int& w, int& h);

	private:
		EventManager();

		EventManager(const EventManager&) = delete;
		EventManager(const EventManager&&) = delete;
		EventManager& operator=(const EventManager&) = delete;
		EventManager&& operator=(const EventManager&&) = delete;

		static void KeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void TextEvent(GLFWwindow* window, unsigned int codepoint);
		static void CursorMoveEvent(GLFWwindow* window, double xpos, double ypos);
		static void CursorEnterEvent(GLFWwindow* window, int entered);
		static void MouseButtonEvent(GLFWwindow* window, int button, int action, int mods);
		static void ScrollEvent(GLFWwindow* window, double xoffset, double yoffset);
		static void WindowReSize(GLFWwindow* window, int w, int h);

		std::vector<Event*>& GetEventList();

		std::vector<Event*> eventList;

		GLFWwindow* window;
	};
}