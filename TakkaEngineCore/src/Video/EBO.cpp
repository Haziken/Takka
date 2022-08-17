#include "../../include/Video/EBO.h"

Takka::EBO::EBO() noexcept : Buffer(GL_ELEMENT_ARRAY_BUFFER) {}

Takka::EBO::EBO(Array<GLuint>& data, GLenum renderType) noexcept : Buffer(GL_ELEMENT_ARRAY_BUFFER)
{
	LoadData(data, renderType);
	indices = data.GetSizeOfVector();
}

Takka::EBO::EBO(const EBO& buffer) noexcept : Buffer(buffer)
{
	indices = buffer.indices;
}

Takka::EBO::EBO(EBO&& buffer) noexcept : Buffer(std::move(buffer))
{
	Swap(*this, buffer);
	std::swap(this->indices, buffer.indices);
}

Takka::EBO& Takka::EBO::operator=(const EBO& buffer) noexcept
{
	BufferCopyData(buffer, *this);
	indices = buffer.indices;
	return *this;
}

Takka::EBO& Takka::EBO::operator=(EBO&& buffer) noexcept
{
	Swap(*this, buffer);
	std::swap(this->indices, buffer.indices);
	return *this;
}

GLuint Takka::EBO::GetIndices()
{
	return indices;
}

void Takka::EBO::SetIndices(GLuint indices)
{
	this->indices = indices;
}