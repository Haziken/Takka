#pragma once

#include "Buffer.h"
#include "Array.h"

namespace Takka
{
	class VBO : public virtual Buffer
	{
	public:
		VBO() noexcept;
		VBO(Array<GLfloat>& vertexes, GLenum renderType = GL_STATIC_DRAW) noexcept;

		VBO(const VBO& buffer) noexcept;
		VBO(VBO&& buffer) noexcept;

		VBO& operator=(const VBO& buffer) noexcept;
		VBO& operator=(VBO&& buffer) noexcept;
	};
}