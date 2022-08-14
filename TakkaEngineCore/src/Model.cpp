#include <Model.h>

Takka::Model::Model(const std::string& path)
{
	LoadModel(path);
}

Takka::Model::Model(const Model& model)
{
	this->meshes = model.meshes;
	this->directory = model.directory;
}

void Takka::Model::LoadModel(const std::string& path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		LERROR("Error load model: ", path, "\n", importer.GetErrorString());
		return;
	}
	directory = path.substr(0, path.find_last_of('/'));
	processNode(scene->mRootNode, scene);
}

void Takka::Model::Draw(Shader& sh)
{
	for (auto& i : meshes)
		i.Draw(sh);
}

void Takka::Model::processNode(aiNode* node, const aiScene* scene)
{
	for (size_t i = 0; i < node->mNumMeshes; ++i)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}

	for (size_t i = 0; i < node->mNumChildren; ++i)
		processNode(node->mChildren[i], scene);
}

Takka::Mesh Takka::Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	Takka::Array<Takka::Mesh::Vertex> verteces;
	Takka::Array<GLuint> indices;
	Takka::Array<Takka::Texture> textures;

	for (size_t i = 0; i < mesh->mNumVertices; ++i)
	{
		Takka::Mesh::Vertex vertex;
		vertex.Position.x = mesh->mVertices[i].x;
		vertex.Position.y = mesh->mVertices[i].y;
		vertex.Position.z = mesh->mVertices[i].z;

		vertex.Normal.x = mesh->mNormals[i].x;
		vertex.Normal.y = mesh->mNormals[i].y;
		vertex.Normal.z = mesh->mNormals[i].z;

		if (mesh->mTextureCoords[0])
		{
			vertex.TexCoords.x = mesh->mTextureCoords[0][i].x;
			vertex.TexCoords.y = mesh->mTextureCoords[0][i].y;
		}
		else
			vertex.TexCoords = glm::vec2(0);

		verteces += vertex;
	}

	for (size_t i = 0; i < mesh->mNumFaces; ++i)
	{
		aiFace face = mesh->mFaces[i];
		for (size_t j = 0; j < face.mNumIndices; ++j)
			indices += face.mIndices[j];
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		textures += loadMaterialTexture(material, aiTextureType_DIFFUSE, Takka::Texture::Type::DIFFUSE);
		textures += loadMaterialTexture(material, aiTextureType_SPECULAR, Takka::Texture::Type::SPECULAR);
	}

	return Takka::Mesh(verteces, indices, textures);
}

Takka::Array<Takka::Texture> Takka::Model::loadMaterialTexture(aiMaterial* mat, aiTextureType type, Takka::Texture::Type typeName)
{
	std::vector<Takka::Texture> textures;
	for (size_t i = 0; i < mat->GetTextureCount(type); ++i)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Takka::Texture texture;
		texture.LoadTexture(directory + str.C_Str(), typeName);
		textures.push_back(texture);
	}
	return Takka::Array<Takka::Texture>(textures);
}
