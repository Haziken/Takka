#include <Video/Buffer.h>

Takka::Buffer::Buffer(GLenum type) : type(type)
{
	glGenBuffers(1, &id);
}

Takka::Buffer::Buffer(Buffer& buffer)
{
	glGenBuffers(1, &id);
	BufferCopyData(buffer, *this);
}

Takka::Buffer& Takka::Buffer::operator=(Buffer& buffer)
{
	BufferCopyData(buffer, *this);
	return *this;
}

Takka::Buffer::~Buffer()
{
	std::cout << "Delete buffer: " << id << std::endl;
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

void Takka::Buffer::BufferCopyData(Buffer& readBuffer, Buffer& writeBuffer)
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