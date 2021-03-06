#pragma once

#include <Video/VBO.h>
#include <Video/EBO.h>
#include <Shader.h>

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

		~VAO();

		void AddEBO(EBO& ebo);
		void AddVBO(VBO& vbo);

		GLuint GetID();
		GLuint GetIndices();

		void Bind();
		void UnBind();

		void EnableArray(GLuint arrayID);
		void DisableArray(GLuint arrayID);

		void AddAttribPointer(GLuint id, GLuint size, GLuint dataSize, GLuint dataIndent = 0, GLenum dataType = GL_FLOAT, GLboolean normalaze = GL_FALSE);

		void Draw(Shader& shader, GLuint indent = 0); // Shader

	private:
		
		GLuint id = 0;
		VBO vbo;
		EBO ebo;
	};
}