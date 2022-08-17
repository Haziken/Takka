#pragma once
#include <string>
#include <iostream>
#include <fstream>

namespace Takka
{
	inline std::string ReadFile(std::string path)
	{
		std::ifstream file(path);
		return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	}
}