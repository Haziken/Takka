#pragma once
#include <string>
#include <iostream>
#include <fstream>

#define DELCPY(a)	a(const a&) = delete;\
					a(a&&) = delete;\
					a operator=(const a&) = delete;\
					a operator=(a&&) = delete;

namespace Takka
{
	inline std::string ReadFile(std::string path)
	{
		std::ifstream file(path);
		return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	}
}