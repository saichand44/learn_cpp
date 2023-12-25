#include <iostream>
#include <string.h>

// String is an array of characters (char - 1 byte)

void PrintString(std::string name)
{   
    // If we have to do any modifications to the strings, it will be only
    // reflected in this fucntin and not the original string as stack memory just
    // creates copies of the variables before passing into the fucntion.

    // If we want to modify the original strings as well, use pass by reference!
    std::cout << name << std::endl;
}

int main()
{   
    // Here const is used as a good practise to avoid unecessary manipulations
    const char* name = "HollowMike"; // memory allocated in stack

    // Here the compiler basically refers to the null terminator "\0" to know that
    // we reached the end of the string
    std::cout << name << std::endl;

    // This will print garbage values at the end of the string as we don't have
    // the null terminator
    char name2[10] = {'H','o','l','l','o','w','M','i','k','e'};
    std::cout << name2 << std::endl;

    // This will function idetntical to const char* definition of string
    char name3[11] = {'H','o','l','l','o','w','M','i','k','e', '\0'};
    std::cout << name3 << std::endl; 

    // using builtin defintion from <string.h>
    std::string name4 = "HollowMike_StringDef";
    std::cout << name4 << std::endl;

}   