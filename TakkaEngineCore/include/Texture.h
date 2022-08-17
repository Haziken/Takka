#pragma once

#include <glad/glad.h>
#include "Logger.h"

namespace Takka {
    class Texture
    {
    public:

        enum class Type
        {
            NONE,
            IMAGE,
            DIFFUSE,
            SPECULAR,
            NORMAL,
            PARALLAX,
            STENCIL,
            MIRROR,
            SKYDOME,
            LIGHT,
        };

        Texture() noexcept;
        Texture(const std::string& path, Type type = Type::IMAGE, GLenum target = GL_TEXTURE_2D) noexcept;
        ~Texture() noexcept;

        Texture(const Texture& texture) noexcept;
        Texture(Texture&& texture) noexcept;

        Texture& operator=(const Texture& texture) noexcept;
        Texture& operator=(Texture&& texture) noexcept;

        void LoadTexture(const std::string& path, Type type = Type::IMAGE, GLenum target = GL_TEXTURE_2D);

        unsigned char* GetData();

        void Bind();
        void UnBind();

        void Activate(GLenum texPref);

        void SetParameteri(GLenum param, GLint value);

        Type GetType();
        GLuint GetId();

        static void TextureCopyData(const Texture& src, Texture& dst);

    private:
        GLint w = 0, h = 0;
        GLuint id = 0;
        Type type = Type::NONE;
        GLenum target = GL_TEXTURE_2D;
    };
}
