#include <iostream>
#include "../include/log.h"

// Using if, else statements basically create a different branches of instructions
// in the memory and when a condition is satisfied, the instructions at that
// particular memory locations are executed. So naturally, if-else statements
// carry an overhead in terms of memory (But might not be too noticeable unless
// we are looking for optimization)

int main()
{
    int x = 4;
    bool compareResult = x == 5;

    // Here "==" is an overloaded statement, meaning, it carries intructions to
    // compare the values at the memory locations of the entities under comparision
    // and return true/false depending on the comparision

    if (compareResult)     // can directly use the comparision instead of 2 steps
    // basically if statement works when the value != 0 (even negative values) 
    // and doesn't work when value = 0

    // no need to use use curly braces when we have only one line
    {
        Log("Hello World");
    }

    else if (x == 5)          
    // this will be executed only when previous statements fail
    {
        Log("Hey World");
    }

    else
    {
        Log("Hey World");
    }

}