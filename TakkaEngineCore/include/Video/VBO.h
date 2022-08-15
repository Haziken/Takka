#pragma once

#include <Utils.h>
#include <Video/Buffer.h>
#include <Video/Array.h>

namespace Takka
{
	class VBO : public virtual Buffer
	{
	public:
		VBO();
		VBO(Array<GLfloat>& vertexes, GLenum renderType = GL_STATIC_DRAW);
		VBO(const VBO& buffer);
		VBO& operator=(const VBO& buffer);
	};
}