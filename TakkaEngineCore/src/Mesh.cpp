#include <Mesh.h>

Takka::Mesh::Mesh(Array<Vertex> vertices, Array<GLuint> indices, Array<Texture> texture) : vertices(vertices), indices(indices), texture(texture)
{
	GenVAO();
}

Takka::Mesh::Mesh(Mesh& mesh)
{
	vertices = mesh.vertices;
	indices = mesh.indices;
	texture = mesh.texture;
	GenVAO();
}

Takka::Mesh::Mesh(Mesh&& mesh)
{
	vertices = mesh.vertices;
	indices = mesh.indices;
	texture = mesh.texture;
	GenVAO();
}

Takka::Mesh& Takka::Mesh::operator=(Mesh& mesh)
{
	vertices = mesh.vertices;
	indices = mesh.indices;
	texture = mesh.texture;
	return *this;
}

Takka::Mesh& Takka::Mesh::operator=(Mesh&& mesh)
{
	vertices = mesh.vertices;
	indices = mesh.indices;
	texture = mesh.texture;
	return *this;
}

void Takka::Mesh::Draw(Shader& sh)
{
	unsigned int diff = 1;
	unsigned int spec = 1;

	for (size_t i = 0; i < texture.GetSizeOfVector(); ++i)
	{
		Takka::Texture& tex = texture.GetVector().at(i);
		if (tex.GetType() == Takka::Texture::Type::DIFFUSE)
		{
			sh.LoadUniformData(("material.diffuse" + std::to_string(diff++)), (float)i);
		}
		else if (tex.GetType() == Takka::Texture::Type::SPECULAR)
		{
			sh.LoadUniformData(("material.specular" + std::to_string(diff++)), (float)i);
		}
		tex.Bind();
	}
	glActiveTexture(GL_TEXTURE0);
	vao.Draw(sh);
}

void Takka::Mesh::GenVAO()
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
