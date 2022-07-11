#pragma once

#include <Video/Buffer.h>

namespace Takka
{
	class EBO : public Buffer
	{
	public:
		DELCPY(EBO);
		EBO();
		EBO(Array<GLuint>& data, GLenum renderType = GL_STATIC_DRAW);

		GLuint GetIndices();
		void SetIndices(GLuint indices);

	private:
		GLuint indices = 0;
	};
}