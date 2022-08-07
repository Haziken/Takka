#pragma once
#include <glm.hpp>
#include <Video/VAO.h>

namespace Takka
{
	class TObject
	{
	public:
		TObject();
		TObject(VAO vao);
		TObject(glm::mat4 model);
		TObject(VAO vao, glm::mat4 model);
		~TObject();

		void Rotate(float angle, glm::vec3 axis);
		void Move(glm::vec3 move);
		void Scale(glm::vec3 scale);

		glm::mat4 GetMode();

	private: 
		VAO vao;
		glm::mat4 model;
	};
}