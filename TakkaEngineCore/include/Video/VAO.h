#pragma once

#include "VBO.h"
#include "EBO.h"
#include "../Shader.h"

namespace Takka
{
	class VAO
	{
	public:

		struct AttribPointer
		{
			GLuint index;
			GLuint size;
			GLenum type;
			GLboolean normalaized;
			GLsizei stride;
			const void* pointer;
		};

		VAO() noexcept;
		VAO(VBO& vbo) noexcept;
		VAO(EBO& ebo) noexcept;
		VAO(VBO& vbo, EBO& ebo) noexcept;

		VAO(const VAO& vao) noexcept;
		VAO(VAO&& vao) noexcept;

		VAO& operator=(const VAO& vao) noexcept;
		VAO& operator=(VAO&& vao) noexcept;

		~VAO() noexcept;

		void AddEBO(EBO& ebo);
		void AddVBO(VBO& vbo);

		GLuint GetID();
		GLuint GetIndices();

		void Bind();
		void UnBind();

		void EnableArray(GLuint arrayID);
		void DisableArray(GLuint arrayID);

		void AddAttribPointer(GLuint id, GLuint size, GLuint dataSize, GLuint dataIndent = 0, GLenum dataType = GL_FLOAT, GLboolean normalaze = GL_FALSE);
		void AddAttribPointer(AttribPointer point);

		void Draw(Shader& shader, GLuint indent = 0);

	private:

		Array<AttribPointer> attribVector;

		GLuint id = 0;
		VBO vbo;
		EBO ebo;
	};
}