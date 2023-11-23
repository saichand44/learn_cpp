#include <iostream>


// Pointers store the memory addresses. The datatype is not that relevant as they
// are just convenience for our reference as to what data type we are dealing with.
// So pointers irrespective of datatype store the address of the data and that
// address is int (in hex notation)

int main()
{   
    // This is a null pointer, meaning that it is DEFINITELY not pointing to anything.
    // It is different from a uniniialized pointer.
    // If we try to access the memory of a null pointer, the program crashes as
    // we are accessing memory that doesn't exist 
    void *ptr = nullptr;

    // This is valid as types do not matter for pointers as they just store the
    // addresses. But if we try to do any manipulations of the data at the 
    // memory location, then we need to do typecasting. So to avoid this, we might
    // as well give the datatype when defining a pointer.
    int var = 8;
    void *ptr2 = &var;
    std::cout << ptr2 << std::endl;     // this gives the memory address

    int var1 = 8;
    int *ptr3 = &var1;
    // * is a dereferencing operator to get the data from the pointer
    std::cout << *ptr3 << std::endl;     // this gives the data at the address

}