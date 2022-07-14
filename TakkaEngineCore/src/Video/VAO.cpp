#include <Video/VAO.h>

Takka::VAO::VAO()
{
	glGenVertexArrays(1, &id);
}

Takka::VAO::VAO(VBO& vbo)
{
	glGenVertexArrays(1, &id);
	AddVBO(vbo);
}

Takka::VAO::VAO(EBO& ebo)
{
	glGenVertexArrays(1, &id);
	AddEBO(ebo);
}

Takka::VAO::VAO(VBO& vbo, EBO& ebo)
{
	glGenVertexArrays(1, &id);
	AddEBO(ebo);
	AddVBO(vbo);
}

void Takka::VAO::AddEBO(EBO& ebo)
{
	Bind();
	ebo.Bind();
	indices = ebo.GetIndices();
	UnBind();
}

void Takka::VAO::AddVBO(VBO& vbo)
{
	Bind();
	vbo.Bind();
	UnBind();
}

GLuint Takka::VAO::GetID()
{
	return id;
}

GLuint Takka::VAO::GetIndices()
{
	return indices;
}

void Takka::VAO::Bind()
{
	glBindVertexArray(id);
}

void Takka::VAO::UnBind()
{
	glBindVertexArray(0);
}

void Takka::VAO::EnableArray(GLuint arrayID)
{
	glEnableVertexAttribArray(arrayID);
}

void Takka::VAO::DisableArray(GLuint arrayID)
{
	glDisableVertexAttribArray(arrayID);
}

void Takka::VAO::AddAttribPointer(GLuint id, GLuint size, GLuint dataSize, GLuint dataIndent, GLenum dataType, GLboolean normalaze)
{
	Bind();
	glVertexAttribPointer(id, size, dataType, normalaze, dataSize, (void*)dataIndent);
	EnableArray(id);
	UnBind();
}

void Takka::VAO::Draw(Shader& shader, GLuint indent)
{
	shader.Use();
	Bind();
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, (void*)indent);
	UnBind();
}
