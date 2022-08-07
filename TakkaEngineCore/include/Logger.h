#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define LOGGER Takka::Logger::Instance()

#define LFATAL(...) LOGGER->Log(Takka::Logger::LOGLEV::FATAL, __VA_ARGS__)
#define LERROR(...) LOGGER->Log(Takka::Logger::LOGLEV::ERROR, __VA_ARGS__)
#define LWARN(...) LOGGER->Log(Takka::Logger::LOGLEV::WARN, __VA_ARGS__)
#define LINFO(...) LOGGER->Log(Takka::Logger::LOGLEV::INFO, __VA_ARGS__)
#define LDEBUG(...) LOGGER->Log(Takka::Logger::LOGLEV::DEBUG, __VA_ARGS__)
#define LTRACE(...) LOGGER->Log(Takka::Logger::LOGLEV::TRACE, __VA_ARGS__)

namespace Takka {
    class Logger
    {
    public:

        enum class LOGLEV
        {
            FATAL,
            ERROR,
            WARN,
            INFO,
            DEBUG,
            TRACE
        };

        static Logger* Instance();
        void Init(const std::string& PathToLogFile);

        template<typename... Args>
        void Log(LOGLEV level, Args... args);

    private:
        Logger();

        template<typename T, typename... Args>
        void CreateMessage(T first, Args... args);

        template<typename T>
        void CreateMessage(T first);

        std::string GetTime();

        std::ofstream logFile;
#ifdef WIN32
        void SetConsoleColor(uint16_t color);
        void* hConsole = nullptr;
#endif
    };

    template<typename ...Args>
    inline void Logger::Log(LOGLEV level, Args ...args)
    {
        std::cout << GetTime();
        logFile << GetTime();
        static std::vector<std::string> prefix = { " FATAL ", " ERROR ", " WARN ", " INFO ", " DEBUG ", " TRACE " };
#ifdef WIN32
        static std::vector<uint16_t> color = { 64,12,6,2,1,7 };
        std::cout << "[";
        SetConsoleColor(color[(int)level]);
        std::cout << prefix[(int)level];
        SetConsoleColor(7);
        std::cout << "]: ";
#else
        static std::vector<std::string> color = {
                "\33[1;30;41m",
                "\33[1;31m",
                "\33[1;91m",
                "\33[1;32m",
                "\33[1;36m",
                "\33[1;97m"
        };
        std::cout << "[" << color[(int)level] << prefix[(int)level] << "\033[0m" << "]: ";
#endif
        CreateMessage(args...);
        std::cout << std::endl;
        logFile << std::endl;
    }

    template<typename T, typename ...Args>
    inline void Logger::CreateMessage(T first, Args ...args)
    {
        std::cout << first;
        logFile << first;
        CreateMessage(args...);
    }

    template<typename T>
    inline void Logger::CreateMessage(T first)
    {
        std::cout << first;
        logFile << first;
    }
}
