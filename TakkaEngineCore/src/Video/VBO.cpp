#include "../../include/Video/VBO.h"

Takka::VBO::VBO() noexcept : Buffer(GL_ARRAY_BUFFER) {}

Takka::VBO::VBO(Array<GLfloat>& vertexes, GLenum renderType) noexcept : Buffer(GL_ARRAY_BUFFER)
{
	LoadData(vertexes, renderType);
}

Takka::VBO::VBO(const VBO& buffer) noexcept : Buffer(buffer)
{}

Takka::VBO::VBO(VBO&& buffer) noexcept : Buffer(std::move(buffer))
{}

Takka::VBO& Takka::VBO::operator=(const VBO& buffer) noexcept
{
	BufferCopyData(buffer, *this);
	return *this;
}

Takka::VBO& Takka::VBO::operator=(VBO&& buffer) noexcept
{
	Swap(*this, buffer);
	return *this;
}
