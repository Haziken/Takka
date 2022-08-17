#include "../include/Object.h"

#include "../include/ORegister.h"

Takka::TObject::TObject(const std::string& name, glm::mat4 model) noexcept : name(name), model(model)
{
	Takka::ObjectRegister::instance().Registrate(this);
}

Takka::TObject::TObject(TObject&& obj) noexcept
{
}

Takka::TObject& Takka::TObject::operator=(TObject&& obj) noexcept
{
	return *this;
}

void Takka::TObject::Rotate(float angle, glm::vec3 axis)
{
	model = glm::rotate(model, glm::radians(angle), axis);
}

void Takka::TObject::Scale(glm::vec3 scaleVec)
{
	model = glm::scale(model, scaleVec);
}

void Takka::TObject::Move(glm::vec3 moveVec)
{
	model = glm::translate(model, moveVec);
}

glm::mat4 Takka::TObject::GetModel()
{
	return model;
}

std::string const Takka::TObject::GetName()
{
	return name;
}
