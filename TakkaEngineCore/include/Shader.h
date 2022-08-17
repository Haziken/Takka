#pragma once

#include "Utils.h"
#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Logger.h"

namespace Takka
{
	class Shader
	{
	public:

		Shader(const Shader&) = delete;
		Shader(Shader&& sh) noexcept;

		Shader& operator=(const Shader&) = delete;
		Shader& operator=(Shader&& sh) noexcept;

		Shader() noexcept;
		Shader(GLuint id) noexcept;
		Shader(const std::string& vertex, const std::string& fragment) noexcept;
		~Shader() noexcept;

		GLuint GetID();

		void Use();
		
		GLuint GetUniformID(const std::string& uniform);

		// matrix
		void LoadUniformData(const std::string& uniformName, glm::mat4 data);
		static void LoadUniformData(GLuint uniformID, glm::mat4 data);
		void LoadUniformData(const std::string& uniformName, glm::mat3 data);
		static void LoadUniformData(GLuint uniformID, glm::mat3 data);
		void LoadUniformData(const std::string& uniformName, glm::mat2 data);
		static void LoadUniformData(GLuint uniformID, glm::mat2 data);

		// vector
		void LoadUniformData(const std::string& uniformName, glm::vec4 data);
		static void LoadUniformData(GLuint uniformID, glm::vec4 data);
		void LoadUniformData(const std::string& uniformName, glm::vec3 data);
		static void LoadUniformData(GLuint uniformID, glm::vec3 data);
		void LoadUniformData(const std::string& uniformName, glm::vec2 data);
		static void LoadUniformData(GLuint uniformID, glm::vec2 data);
		void LoadUniformData(const std::string& uniformName, glm::vec1 data);
		static void LoadUniformData(GLuint uniformID, glm::vec1 data);

		// simple data 
		void LoadUniformData(const std::string& uniformName, GLint data);
		static void LoadUniformData(GLuint uniformID, GLint data);
		void LoadUniformData(const std::string& uniformName, GLuint data);
		static void LoadUniformData(GLuint uniformID, GLuint data);
		void LoadUniformData(const std::string& uniformName, GLfloat data);
		static void LoadUniformData(GLuint uniformID, GLfloat data);

		void CreateProgram(const std::string& vertex, const std::string& fragment);

	private:
		static GLuint CreateShaderProgram(const std::string& code, GLenum shaderType);
		GLuint id = 0;
	};
}