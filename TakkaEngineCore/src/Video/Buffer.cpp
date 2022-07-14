#include <Video/Buffer.h>

Takka::Buffer::Buffer(GLenum type) : type(type) 
{
	glGenBuffers(1, &id);
}

Takka::Buffer::Buffer(GLuint id, GLenum type) : id(id), type(type)
{}

Takka::Buffer::~Buffer()
{
	//glDeleteBuffers(1, &id);
}

Takka::Buffer::Buffer(const Buffer& buffer) : id(buffer.id), type(buffer.type)
{}

Takka::Buffer::Buffer(Buffer& buffer) : id(buffer.id), type(buffer.type)
{}

Takka::Buffer& Takka::Buffer::operator=(const Buffer & buffer)
{
	this->id = buffer.id;
	this->type = buffer.type;
	return *this;
}

Takka::Buffer& Takka::Buffer::operator=(Buffer& buffer)
{
	this->id = buffer.id;
	this->type = buffer.type;
	return *this;
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

void Takka::Buffer::Delete()
{
	glDeleteBuffers(1, &id);
}
