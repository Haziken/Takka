#include <Video/EBO.h>

Takka::EBO::EBO() : Buffer(GL_ELEMENT_ARRAY_BUFFER) {}

Takka::EBO::EBO(Array<GLuint>& data, GLenum renderType) : Buffer(GL_ELEMENT_ARRAY_BUFFER)
{
	LoadData(data, renderType);
	indices = data.getSizeOfVector();
}

GLuint Takka::EBO::GetIndices()
{
	return indices;
}

void Takka::EBO::SetIndices(GLuint indices)
{
	this->indices = indices;
}