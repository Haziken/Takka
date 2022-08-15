#pragma once

#include "Buffer.h"

namespace Takka
{
	class EBO : public virtual Buffer
	{
	public:
		EBO();
		EBO(Array<GLuint>& data, GLenum renderType = GL_STATIC_DRAW);
		EBO(const EBO& buffer);
		EBO& operator=(const EBO& buffer);

		GLuint GetIndices();
		void SetIndices(GLuint indices);

	private:
		GLuint indices = 0;
	};
}