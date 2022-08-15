#pragma once

#include "Utils.h"
#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Shader.h"
#include <cmath>

namespace Takka
{
	class Camera
	{
	public:
		DELCPY(Camera);
		Camera(GLuint widht, GLuint height, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
			float yaw = 45,
			float pitch = 0, float fov = 90);

		void LoadMatrixInShader(Shader& sheder, std::string viewMatrixName = "view", std::string projectionMatrix = "project");

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectMatrix();

		glm::vec3 GetPosition();
		void SetPosition(glm::vec3 position);

		GLfloat GetYaw();
		void SetYaw(GLfloat yaw);

		GLfloat GetPitch();
		void SetPitch(GLfloat pitch);

		GLfloat GetFov();
		void SetFov(GLfloat fov);

		glm::vec3 GetFront();
		glm::vec3 GetRight();

	private:
		void UpdateVectors();

		glm::vec3 position;
		glm::vec3 front;
		glm::vec3 up;
		glm::vec3 right;
		glm::vec3 worldUp;
		// Euler angles
		GLfloat yaw;
		GLfloat pitch;
		// Camera settings
		GLfloat fov;

		GLuint w, h;
	};
}