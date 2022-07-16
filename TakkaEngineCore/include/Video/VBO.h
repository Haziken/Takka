#pragma once

#include <Utils.h>
#include <Video/Buffer.h>
#include <Video/Array.h>

namespace Takka
{
	class VBO : public Buffer
	{
	public:
		VBO();
		VBO(Array<GLfloat>& vertexes, GLenum renderType = GL_STATIC_DRAW);
		VBO(VBO& buffer);
		VBO& operator=(VBO& buffer);
	};
}