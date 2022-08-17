#pragma once 

#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace Takka
{
	class TObject
	{
	public:
		TObject(const std::string& name, glm::mat4 model = glm::mat4(1.0f)) noexcept;

		TObject(const TObject& obj) noexcept;
		TObject(TObject&& obj) noexcept;

		TObject& operator=(const TObject& obj) noexcept;
		TObject& operator=(TObject&& obj) noexcept;

		void Rotate(float angle, glm::vec3 axis);
		void Scale(glm::vec3 scaleVec);
		void Move(glm::vec3 moveVec);

		glm::mat4 GetModel();
		std::string const GetName();

	private:
		glm::mat4 model = glm::mat4(1.0f);
		std::string name;
	};
}