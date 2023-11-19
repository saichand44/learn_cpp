// Data Types:
// 1. Primitive 2. Derived 3. Abstract

// Primitive Datatypes : (all "int, char" types have signed and unsigned options)
// a) int: (4 bytes and signed) range: -2147483648 to 2147483647 
//         (1 bit - sign and 31 bits for value)
//    short (2 bytes --> signed and unsigned)
//    long (8 bytes --> signed and unsigned)
// b) char: (1 byte) Can be assigned a symbol using single quotes or direclty 
//                   assign a number that corresponds to the ascii characters
// c) float: (4 bytes and single precision) 
// d) double: (8 bytes and double precision)
// e) void: Typically used in functions that do not return anything

// use sizeof(data_type) to get the size of the data type

#include <iostream>

int main()
{
    int variable = 8;
    unsigned int variable_2 = 16;     // basically uses all 32 bits for value

    std::cout << variable << std::endl;
    std::cout << variable_2 << std::endl;

    // both of these char definitions yield the same
    char a_symbol = 'A';
    char a_ascii = 65;     // number in the ascii reference for letter A
    std::cout << a_symbol << std::endl;
    std::cout << a_ascii << std::endl;

    // just using "float" will not make a differene as the variable is still
    // assigned a "double" data type
    // To use float data type use this "float variable = 5.5f"; "f" is imp.
    float float_var = 5.5f;
    double double_var = 5.5;
    std::cout << float_var << std::endl;
    std::cout << double_var << std::endl;

}

