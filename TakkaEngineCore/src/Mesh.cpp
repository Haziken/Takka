#include "../include/Mesh.h"

Takka::Mesh::Mesh(Array<Vertex> vertices, Array<GLuint> indices, Array<Texture> texture) noexcept : texture(texture)
{
	VBO vbo;
	vbo.LoadData(vertices, GL_STATIC_DRAW);
	EBO ebo(indices);

	vao.AddVBO(vbo);
	vao.AddEBO(ebo);

	vao.AddAttribPointer(0, 3, sizeof(Vertex));
	vao.AddAttribPointer(1, 3, sizeof(Vertex), offsetof(Vertex, Normal));
	vao.AddAttribPointer(2, 2, sizeof(Vertex), offsetof(Vertex, TexCoords));
}

Takka::Mesh::Mesh(const Mesh& mesh) noexcept
{
	texture = mesh.texture;
	vao = mesh.vao;
}

Takka::Mesh::Mesh(Mesh&& mesh) noexcept
{
	std::swap(this->vao, mesh.vao);
	std::swap(this->texture, mesh.texture);
}

Takka::Mesh& Takka::Mesh::operator=(const Mesh& mesh) noexcept
{
	texture = mesh.texture;
	vao = mesh.vao;
	return *this;
}

Takka::Mesh& Takka::Mesh::operator=(Mesh&& mesh) noexcept
{
	std::swap(this->vao, mesh.vao);
	std::swap(this->texture, mesh.texture);
	return *this;
}

void Takka::Mesh::Draw(Shader& sh)
{
	unsigned int diff = 1;
	unsigned int spec = 1;

	//for (size_t i = 0; i < texture.GetSizeOfVector(); ++i)
	//{
	//	Takka::Texture& tex = texture.GetVector().at(i);
	//	if (tex.GetType() == Takka::Texture::Type::DIFFUSE)
	//	{
	//		//sh.LoadUniformData(("diffuse" + std::to_string(diff++)), (float)i);
	//	}
	//	else if (tex.GetType() == Takka::Texture::Type::SPECULAR)
	//	{
	//		//sh.LoadUniformData(("material.specular" + std::to_string(diff++)), (float)i);
	//	}
	//	tex.Bind();
	//}
	//glActiveTexture(GL_TEXTURE0);
	Takka::Texture& t = texture.GetVector().at(0);
	t.Activate(GL_TEXTURE0);
	t.Bind();
	vao.Draw(sh);
}
