#include <Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Takka::Texture::Texture()
{
	glGenTextures(1, &id);
}

Takka::Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void Takka::Texture::LoadTexture(const std::string& path)
{
	Bind();
	int w, h, nrCh;
	const char* d = path.c_str();
	unsigned char* data = stbi_load(d, &w, &h, &nrCh, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data);
	UnBind();
}

void Takka::Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}

void Takka::Texture::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Takka::Texture::Activate(GLenum texPref)
{
	glActiveTexture(texPref);
}

void Takka::Texture::SetParameteri(GLenum param, GLint value)
{
	Bind();
	glTexParameteri(GL_TEXTURE_2D, param, value);
	UnBind();
}
