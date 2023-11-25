#include <iostream>

class Log
{
// Here we have separate secctions for variables (public and private) &
// functions (public and private)
public:
    // const means these variables are not allowed for modifications during run time
    const int LogLevelError   = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo    = 2;

private:
    int m_LogLevel = LogLevelInfo;  // good pratice to use member variable with m_ and
                                    // local variable as is
public:
    void setLevel(int level)
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