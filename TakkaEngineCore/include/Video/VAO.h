#pragma once

#include <Video/VBO.h>
#include <Video/EBO.h>

namespace Takka
{
	class VAO
	{
	public:
		DELCPY(VAO);

		VAO();
		VAO(VBO& vbo);
		VAO(EBO& ebo);
		VAO(VBO& vbo, EBO& ebo);

		void AddEBO(EBO& ebo);
		void AddVBO(VBO& vbo);

		GLuint GetID();
		GLuint GetIndices();

		void Bind();
		void UnBind();

		void EnableArray(GLuint arrayID);
		void DisableArray(GLuint arrayID);

		void AddAttribPointer(GLuint id, GLuint size, GLenum dataType, GLuint dataSize, GLuint dataIndent = 0, GLboolean normalaze = GL_FALSE);

		void Draw(); // Shader

	private:
		GLuint id, indices;
	};
}