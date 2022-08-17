#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>

namespace Takka
{
	inline std::string ReadFile(std::string path)
	{
		std::ifstream file(path);
		return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	}

	inline std::string const GetTime(const std::string& format)
	{
		auto time = std::chrono::system_clock::now();
		auto forFormat = std::chrono::system_clock::to_time_t(time);
		std::stringstream ss;
		ss << std::put_time(std::localtime(&forFormat), format.c_str());
		return ss.str();
	}

	inline double const GetTimeMS()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	}
}