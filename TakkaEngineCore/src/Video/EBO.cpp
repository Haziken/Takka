#include <Video/EBO.h>

Takka::EBO::EBO() : Buffer(GL_ELEMENT_ARRAY_BUFFER) {}

Takka::EBO::EBO(Array<GLuint>& data, GLenum renderType) : Buffer(GL_ELEMENT_ARRAY_BUFFER)
{
	LoadData(data, renderType);
	indices = data.getSizeOfVector();
}

Takka::EBO::EBO(EBO& buffer) : Buffer(buffer)
{
	indices = buffer.indices;
}

Takka::EBO& Takka::EBO::operator=(EBO& buffer)
{
	BufferCopyData(buffer, *this);
	indices = buffer.indices;
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