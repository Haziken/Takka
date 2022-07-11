#include <Video/Buffer.h>

Takka::Buffer::Buffer(GLenum type) : type(type) 
{
	glGenBuffers(1, &id);
}

Takka::Buffer::~Buffer()
{
	glDeleteBuffers(1, &id);
}

void Takka::Buffer::Bind()
{
	glBindBuffer(type, id);
}

void Takka::Buffer::UnBind()
{
	glBindBuffer(type, 0);
}

GLuint Takka::Buffer::GetID()
{
	return id;
}
