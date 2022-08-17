#include "../../include/Video/VAO.h"

Takka::VAO::VAO() noexcept
{
	glGenVertexArrays(1, &id);
}

Takka::VAO::VAO(VBO& vbo) noexcept
{
	glGenVertexArrays(1, &id);
	AddVBO(vbo);
}

Takka::VAO::VAO(EBO& ebo) noexcept
{
	glGenVertexArrays(1, &id);
	AddEBO(ebo);
}

Takka::VAO::VAO(VBO& vbo, EBO& ebo) noexcept
{
	glGenVertexArrays(1, &id);
	AddEBO(ebo);
	AddVBO(vbo);
}

Takka::VAO::VAO(const VAO& vao) noexcept
{
	this->vbo = vao.vbo;
	this->ebo = vao.ebo;

	this->Bind();
	this->vbo.Bind();
	this->ebo.Bind();
	this->UnBind();

	for (auto& i : attribVector.GetVector())
		this->AddAttribPointer(i);
}

Takka::VAO::VAO(VAO&& vao) noexcept
{
	std::swap(this->attribVector, vao.attribVector);
	std::swap(this->ebo, vao.ebo);
	std::swap(this->id, vao.id);
	std::swap(this->vbo, vao.vbo);
}

Takka::VAO& Takka::VAO::operator=(const VAO& vao) noexcept
{
	this->vbo = vao.vbo;
	this->ebo = vao.ebo;

	this->Bind();
	this->vbo.Bind();
	this->ebo.Bind();
	this->UnBind();

	for (auto& i : attribVector.GetVector())
		this->AddAttribPointer(i);

	return *this;
}

Takka::VAO& Takka::VAO::operator=(VAO&& vao) noexcept
{
	std::swap(this->attribVector, vao.attribVector);
	std::swap(this->ebo, vao.ebo);
	std::swap(this->id, vao.id);
	std::swap(this->vbo, vao.vbo);
	return *this;
}

Takka::VAO::~VAO() noexcept
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

	attribVector += AttribPointer(id, size, dataType, normalaze, dataSize, (void*)dataIndent);
}

void Takka::VAO::AddAttribPointer(AttribPointer point)
{
	Bind();
	glVertexAttribPointer(point.index, point.size, point.type, point.normalaized, point.stride, point.pointer);
	EnableArray(point.index);
	UnBind();

	attribVector += point;
}

void Takka::VAO::Draw(Shader& shader, GLuint indent)
{
	shader.Use();
	Bind();
	if (ebo.GetIndices() == 0)
		glDrawArrays(GL_TRIANGLES, 0, 36);
	else
		glDrawElements(GL_TRIANGLES, ebo.GetIndices(), GL_UNSIGNED_INT, (void*)indent);
	UnBind();
}
