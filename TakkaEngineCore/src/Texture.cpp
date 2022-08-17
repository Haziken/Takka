#include "../include/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <stdlib.h>

Takka::Texture::Texture() noexcept
{
	glGenTextures(1, &id);
}

Takka::Texture::Texture(const std::string& path, Type type, GLenum target) noexcept
{
	glGenTextures(1, &id);
	LoadTexture(path, type, target);
}

Takka::Texture::~Texture() noexcept
{
	glDeleteTextures(1, &id);
}

Takka::Texture::Texture(const Takka::Texture& texture) noexcept
{
	glGenTextures(1, &id);
	TextureCopyData(texture, *this);
}

Takka::Texture::Texture(Texture&& texture) noexcept
{
	std::swap(this->id, texture.id);
	std::swap(this->w, texture.w);
	std::swap(this->h, texture.h);
	std::swap(this->type, texture.type);
	std::swap(this->target, texture.target);
	LDEBUG("Texture ", texture.id, " move to: ", id);
}

Takka::Texture& Takka::Texture::operator=(const Takka::Texture& texture) noexcept
{
	TextureCopyData(texture, *this);
	return *this;
}

Takka::Texture& Takka::Texture::operator=(Texture&& texture) noexcept
{
	std::swap(this->id, texture.id);
	std::swap(this->w, texture.w);
	std::swap(this->h, texture.h);
	std::swap(this->type, texture.type);
	std::swap(this->target, texture.target);
	LDEBUG("Texture ", texture.id, " move to: ", id);
	return *this;
}

void Takka::Texture::LoadTexture(const std::string& path, Type type, GLenum target)
{
	this->type = type;
	this->target = target;

	Bind();
	int nrCh;
	const char* d = path.c_str();
	unsigned char* data = stbi_load(d, &w, &h, &nrCh, 0);
	if (data)
	{
		glTexImage2D(target, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(target);
	}
	stbi_image_free(data);
	UnBind();
}

unsigned char* Takka::Texture::GetData()
{
	unsigned char* texturedata = (unsigned char*)malloc(sizeof(unsigned char) * w * h * 3);
	Bind();
	glGetTexImage(target, 0, GL_RGB, GL_UNSIGNED_BYTE, texturedata);
	UnBind();

	LINFO(texturedata);
	//free(texturedata);

	return 0;
}

void Takka::Texture::Bind()
{
	glBindTexture(target, id);
}

void Takka::Texture::UnBind()
{
	glBindTexture(target, 0);
}

void Takka::Texture::Activate(GLenum texPref)
{
	glActiveTexture(texPref);
}

void Takka::Texture::SetParameteri(GLenum param, GLint value)
{
	Bind();
	glTexParameteri(target, param, value);
	UnBind();
}

Takka::Texture::Type Takka::Texture::GetType()
{
	return type;
}

GLuint Takka::Texture::GetId()
{
	return id;
}

void Takka::Texture::TextureCopyData(const Texture& src, Texture& dst)
{
	if (src.target == dst.target)
	{
		dst.Bind();
		glTexImage2D(dst.target, 0, GL_RGB, src.w, src.h, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
		glGenerateMipmap(dst.target);
		glCopyImageSubData(
			src.id, src.target, 0, 0, 0, 0,
			dst.id, dst.target, 0, 0, 0, 0, 
			src.w, src.h, 0);
		dst.w = src.w;
		dst.h = src.h;
		dst.type = src.type;

		GLenum error;
		if ((error = glGetError()) != GL_NO_ERROR)
		{
			std::cout << std::hex << error << std::endl;
		}
	}
	else
	{
		LERROR("Texture copy failed!");
	}
}
