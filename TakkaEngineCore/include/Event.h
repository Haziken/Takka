#pragma once

#include <string>

namespace Takka { // Event interface
    class Event
    {
    public:
        Event() noexcept;
        ~Event() noexcept;
        
        virtual void KeyPress(int key, int mods) {}
        virtual void KeyRepeat(int key, int mods) {}
        virtual void KeyRelease(int key, int mods) {}
        
        virtual void TextInput(unsigned int codepoint) {}

        virtual void CursorPosition(double x, double y) {}
        virtual void CursorEnder(short int entered) {}

        virtual void MouseButtonPress(int key, int mods) {}
        virtual void MouseButtonRelease(int key, int mods) {}

        virtual void Scroll(double xoffset, double yoffset) {}

        virtual void JoysticConnect(int joysticId) {}
        virtual void JoysticDisconnect(int joysticUd) {}

        virtual void PathDrop(std::string path) {}

        virtual void WindowResize(int w, int h) {}
    };
}
