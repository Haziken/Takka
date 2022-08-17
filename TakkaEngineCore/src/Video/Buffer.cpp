#include "../../include/Video/Buffer.h"

Takka::Buffer::Buffer(GLenum type) noexcept : type(type)
{
	glGenBuffers(1, &id);
}

Takka::Buffer::Buffer(const Buffer& buffer) noexcept
{
	glGenBuffers(1, &id);
	BufferCopyData(buffer, *this);
}

Takka::Buffer::Buffer(Buffer&& buffer) noexcept
{
	Swap(*this, buffer);
}

Takka::Buffer& Takka::Buffer::operator=(const Buffer& buffer) noexcept
{
	BufferCopyData(buffer, *this);
	return *this;
}

Takka::Buffer& Takka::Buffer::operator=(Buffer&& buffer) noexcept
{
	Swap(*this, buffer);
	return *this;
}

Takka::Buffer::~Buffer() noexcept
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

void Takka::Buffer::BufferCopyData(const Buffer& readBuffer, Buffer& writeBuffer)
{
	glBindBuffer(GL_COPY_READ_BUFFER, readBuffer.id);
	glBindBuffer(GL_COPY_WRITE_BUFFER, writeBuffer.id);
	glBufferData(GL_COPY_WRITE_BUFFER, readBuffer.sizeOfData, nullptr, GL_STATIC_DRAW);
	glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, readBuffer.sizeOfData);
	writeBuffer.sizeOfData = readBuffer.sizeOfData;
	writeBuffer.type = readBuffer.type;
	glBindBuffer(GL_COPY_READ_BUFFER, 0);
	glBindBuffer(GL_COPY_WRITE_BUFFER, 0);
}

void Takka::Buffer::Swap(Buffer& l, Buffer& r) noexcept
{
	std::swap(l.id, r.id);
	std::swap(l.sizeOfData, r.sizeOfData);
	std::swap(l.type, r.type);
}
