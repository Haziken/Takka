#include <Video/VBO.h>

Takka::VBO::VBO() : Buffer(GL_ARRAY_BUFFER) {}

Takka::VBO::VBO(Array<GLfloat>& vertexes, GLenum renderType) : Buffer(GL_ARRAY_BUFFER)
{
	LoadData(vertexes, renderType);
}
