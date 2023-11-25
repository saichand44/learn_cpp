#include <iostream>
#include "../include/log.h"

// References are a lot like pointers except they are not any variables that store
// the memory address. They are just aliases to the address of the variable. It is
// basically a syntax sugar that makes the code look cleaner. We can achieve
// the same operations with both pointers and references.

// But with pointers we can intialize them to null pointer meaning they do not
// point to anything and assign when needed. But for reference we always need a
// variable defined as they are just syntax sugar.

void increment_ptr(int *value)
{
    // Here we need to deference first and then do the increment
    (*value)++;
}

// This is acctually just passing by reference, we are sending in the address of
// of the variable and then it is internally derefenced to get th value
void increment_ref(int &value)
{
    value++;
}

int main()
{
    int a = 5;
    int b = 5;

    increment_ptr(&a);
    increment_ref(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    // This is a reference initialization and always have to be initialzed with 
    // some existing variable and these have to unique and be careful when assining
    // new variables to this as they will change the original variables
    int& ref = a;
    // int& ref = a;
    // ref = b; --> this will assign 'a' the value of 'b';
    
}