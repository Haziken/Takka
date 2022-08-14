#pragma once

#include <Video/Buffer.h>

namespace Takka
{
	class EBO : public virtual Buffer
	{
	public:
		EBO();
		EBO(Array<GLuint>& data, GLenum renderType = GL_STATIC_DRAW);
		EBO(EBO& buffer);
		EBO& operator=(EBO& buffer);

		GLuint GetIndices();
		void SetIndices(GLuint indices);

	private:
		GLuint indices = 0;
	};
}