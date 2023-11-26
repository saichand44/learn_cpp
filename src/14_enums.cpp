#include <iostream>

// enum --> enumeration. Basically a set / entity that contains a bunch of variables
// This is only for integers. It helps to keep all variables at once place. 

// The values are incremented by 1 and start with zero for the first one by default.
// But we can assign whatever value we want

class Log
{
// Here we have separate secctions for variables (public and private) &
// functions (public and private)
public:
    enum LogLevel : const int
    {
        LogLevelError=0, LogLevelWarning, LogLevelInfo
    }; //--------------------------------------> remember to put ';' at the end

private:
    LogLevel m_LogLevel = LogLevelInfo;  // good pratice to use member variable with m_ and
                                    // local variable as is
public:
    void setLevel(LogLevel level)     // using the type LogLevel defined in enum
    {
        m_LogLevel = level;
    }

    void Warn(const char* message)
    {
        if (m_LogLevel >= LogLevelWarning)
        {
            std::cout << "[WARNING]: " << message << std::endl;
        }
    }

    void Error(const char* message)
    {
        if (m_LogLevel >= LogLevelError)
        {
            std::cout << "[ERROR]: " << message << std::endl;
        }
    }

    void Info(const char* message)
    {
        if (m_LogLevel >= LogLevelInfo)
        {
            std::cout << "[INFO]: " << message << std::endl;
        }
    }
}; //--------------------------------------> remember to put ';' at the end

int main()
{
    Log log;
    log.setLevel(log.LogLevelInfo);

    log.Warn("Hello!");
    log.Error("Hello!");
    log.Info("Hello!");
}