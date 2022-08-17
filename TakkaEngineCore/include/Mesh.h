#pragma once

#include "Video/VAO.h"
#include "Texture.h"
#include <sstream>

namespace Takka {
    class Mesh
    {
    public:

        struct Vertex
        {
            glm::vec3 Position;
            glm::vec3 Normal;
            glm::vec2 TexCoords;
        };

        Mesh(Array<Vertex> vertices, Array<GLuint> indices, Array<Texture> texture) noexcept;

        Mesh(const Mesh& mesh) noexcept;
        Mesh(Mesh&& mesh) noexcept;

        Mesh& operator=(const Mesh& mesh) noexcept;
        Mesh& operator=(Mesh&& mesh) noexcept;

        void Draw(Shader& sh);

    private:
        VAO vao;
        Array<Texture> texture;
    };
}
