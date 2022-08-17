#pragma once

#include "Buffer.h"

namespace Takka
{
	class EBO : public virtual Buffer
	{
	public:

		EBO(const EBO& buffer) noexcept;
		EBO(EBO&& buffer) noexcept;

		EBO& operator=(const EBO& buffer) noexcept;
		EBO& operator=(EBO&& buffer) noexcept;

		EBO() noexcept;
		EBO(Array<GLuint>& data, GLenum renderType = GL_STATIC_DRAW) noexcept;

		GLuint GetIndices();
		void SetIndices(GLuint indices);

	private:
		GLuint indices = 0;
	};
}