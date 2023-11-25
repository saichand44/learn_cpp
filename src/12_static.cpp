#include <iostream>

// using 'static' will confine the variable scope to that particular file only.
// particularly useful for the global variables to prevent linker errors of
// having same variable name defined elsewhere.

// use it for both variables and functions to limit the scope for those to within
// that particular file

// Also 'static' can be used in functions itself to declare the variable only once
// and when the function is called next time, the static variable is not
// initialized again but istead it uses the value that it was previously carrying
// in the last call

void testForStatic()
{
    static int value = 0;
    std::cout << value << std::endl;
    value++;
}

int main()
{
    for (int i; i<5; i++)
    {
        testForStatic();
    }
}