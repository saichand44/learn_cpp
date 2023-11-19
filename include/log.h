#pragma once // called as header guards
// to use the header file only once and to avoid duplication of the variable/
// functions defined. We can still call the log.h header file multiple times
// but the compiler will use it's contents only once and use it for the .cpp 
// files that are calling the header files

// Alternative for pragma once, using ifndef statment
#ifndef _LOG_H                // the name could be anyting
#define _LOG_H
// blah blah blah
#endif

#include <iostream>

// can use functiond definitions or declarations
void Log(const char* message)
{
    std::cout << message << std::endl;
}




