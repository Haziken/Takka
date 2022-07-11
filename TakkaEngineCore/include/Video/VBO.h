#pragma once

#include <Utils.h>
#include <Video/Buffer.h>
#include <Video/Array.h>

namespace Takka
{
	class VBO : public Buffer
	{
	public:
		DELCPY(VBO);
		VBO();
		VBO(Array<GLfloat>& vertexes, GLenum renderType = GL_STATIC_DRAW);
	};
}