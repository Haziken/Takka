#include <Video/VBO.h>

Takka::VBO::VBO() : Buffer(GL_ARRAY_BUFFER) {}

Takka::VBO::VBO(Array<GLfloat>& vertexes, GLenum renderType) : Buffer(GL_ARRAY_BUFFER)
{
	LoadData(vertexes, renderType);
}

Takka::VBO::VBO(VBO& buffer) : Buffer(buffer)
{}

Takka::VBO& Takka::VBO::operator=(VBO& buffer)
{
	BufferCopyData(buffer, *this);
	return *this;
}