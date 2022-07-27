#pragma once

#include <Utils.h>
#include <glad/glad.h>

namespace Takka {
    class Texture
    {
    public:
        DELCPY(Texture);
        Texture();
        ~Texture();

        void LoadTexture(const std::string& path);

        void Bind();
        void UnBind();

        void Activate(GLenum texPref);

        void SetParameteri(GLenum param, GLint value);

    private:
        GLuint id;
    };
}
