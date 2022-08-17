#include "../include/ORegister.h"

Takka::ObjectRegister& Takka::ObjectRegister::instance()
{
	static ObjectRegister obj;
	return obj;
}

void Takka::ObjectRegister::Registrate(TObject* obj)
{
	steck.insert({ obj->GetName(), obj });
}

Takka::TObject* Takka::ObjectRegister::GetObject(const std::string& name)
{
	return steck.at(name);
}

void Takka::ObjectRegister::UnRegistrate(const std::string& name)
{
	steck.erase(name);
}

void Takka::ObjectRegister::UnRegistrate(TObject* obj)
{
	steck.erase(obj->GetName());
}
