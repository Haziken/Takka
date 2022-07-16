#pragma once

#include <Utils.h>
#include <glad/glad.h>
#include <stb_image.h>

namespace Takka {
    class Texture
    {
    public:
        Texture();
        Texture(std::string path);
        Texture(GLubyte textureData);
        
    };
}
