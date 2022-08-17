#pragma once

#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Takka {
    class Model
    {
    public:
        Model() noexcept {}
        Model(const std::string& path) noexcept;

        Model(const Model& model) noexcept;
        Model(Model&& model) noexcept;

        Model& operator=(const Model& model) noexcept;
        Model& operator=(Model&& model) noexcept;

        void LoadModel(const std::string& path);

        void Draw(Shader& sh);
    private:
        std::vector<Mesh> meshes;
        std::string directory = "";

        void processNode(aiNode* node, const aiScene* scene);
        Mesh processMesh(aiMesh* mesh, const aiScene* scene);
        Array<Texture> loadMaterialTexture(aiMaterial* mat, aiTextureType type, Takka::Texture::Type typeName);
    };
}
