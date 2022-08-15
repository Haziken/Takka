#include "../include/Logger.h"
#ifdef WIN32
#include <Windows.h>
#endif

#include <ctime>
#include <sstream>
#include <iomanip>

Takka::Logger* Takka::Logger::Instance()
{
	static Logger* log = new Logger();
	return log;
}

void Takka::Logger::Init(const std::string& PathToLogFile)
{
	logFile.open(PathToLogFile, std::ios_base::trunc);
#ifdef WIN32
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // WIN32
}

Takka::Logger::Logger() {}

#ifdef WIN32
void Takka::Logger::SetConsoleColor(uint16_t color)
{
	SetConsoleTextAttribute(hConsole, color);
}
#endif

std::string Takka::Logger::GetTime()
{
	auto t = std::time(nullptr);
	std::ostringstream oss;
	oss << std::put_time(std::localtime(&t), "%T ");
	return oss.str();
}