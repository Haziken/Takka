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

Takka::Texture::Texture(const Takka::Texture& texture)
{
	glGenTextures(1, &id);
	TextureCopyData(texture, *this);
}

Takka::Texture::Texture(const Texture&& texture)
{
	glGenTextures(1, &id);
	TextureCopyData(texture, *this);
}

Takka::Texture& Takka::Texture::operator=(const Takka::Texture& texture)
{
	TextureCopyData(texture, *this);
	return *this;
}

Takka::Texture& Takka::Texture::operator=(const Texture&& texture)
{
	TextureCopyData(texture, *this);
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
		glCopyImageSubData(
			src.id, src.target, 0, 0, 0, 0,
			dst.id, dst.target, 0, 0, 0, 0,
			src.w, src.h, 1);
		dst.type = src.type;
		dst.w = src.w;
		dst.h = src.h;
		dst.target = src.target;
	}
	else
	{
		LERROR("Texture copy failed!");
	}
}
