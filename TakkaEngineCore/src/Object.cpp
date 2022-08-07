#include "Object.h"

Takka::TObject::TObject() : model(glm::mat4(1.0f)) {}

//Takka::TObject::TObject(VAO vao) : model(glm::mat4(1.0f)), vao(vao) {}

void Takka::TObject::Rotate(float angle, glm::vec3 axis)
{
	model = glm::rotate(model, glm::radians(angle), axis);
}

void Takka::TObject::Move(glm::vec3 move)
{
	model = glm::translate(model, move);
}

void Takka::TObject::Scale(glm::vec3 scale)
{
	model = glm::scale(model, scale);
}

glm::mat4 Takka::TObject::GetMode()
{
	return model;
}
