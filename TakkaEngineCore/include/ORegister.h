#pragma once

#include <unordered_map>
#include <string>

#include "Object.h"

namespace Takka
{
	class ObjectRegister
	{
	public:
		static ObjectRegister& instance();

		void Registrate(TObject* obj);

		TObject* GetObject(const std::string& name);

		void UnRegistrate(const std::string& name);
		void UnRegistrate(TObject* obj);

	private:
		ObjectRegister();

		std::unordered_map<std::string, TObject*> steck;
	};
}