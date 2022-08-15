#pragma once

#include <Video/VBO.h>
#include <Video/EBO.h>
#include <Shader.h>

namespace Takka
{
	class VAO
	{
	public:
		VAO();
		VAO(VBO& vbo);
		VAO(EBO& ebo);
		VAO(VBO& vbo, EBO& ebo);

		VAO(const VAO& vao);
		VAO& operator=(const VAO& vao);

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

		void Draw(Shader& shader, GLuint indent = 0);

	private:
		
		struct AttribPointer
		{
			GLuint index;
			GLuint size;
			GLenum type;
			GLboolean normalaized;
			GLsizei stride;
			const void* pointer;
		};

		Array<AttribPointer> attribVector;

		GLuint id = 0;
		VBO vbo;
		EBO ebo;
	};
}