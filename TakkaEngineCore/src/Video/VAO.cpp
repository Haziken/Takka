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

Takka::VAO::~VAO()
{
	glDeleteVertexArrays(1, &id);
}

void Takka::VAO::AddEBO(EBO& ebo)
{
	this->ebo = ebo;
	Bind();
	this->ebo.Bind();
	UnBind();
}

void Takka::VAO::AddVBO(VBO& vbo)
{
	this->vbo = vbo;
	Bind();
	this->vbo.Bind();
	UnBind();
}

GLuint Takka::VAO::GetID()
{
	return id;
}

GLuint Takka::VAO::GetIndices()
{
	return ebo.GetIndices();
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
	glDrawElements(GL_TRIANGLES, ebo.GetIndices(), GL_UNSIGNED_INT, (void*)indent);
	UnBind();
}
