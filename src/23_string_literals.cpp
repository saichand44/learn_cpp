#include <iostream>
#include <string.h>

int main() 
{
    const char* name0= "HollowMike";      // 1 byte

    const wchar_t* name1= L"HollowMike";   // 2 bytes
 
    const char16_t* name2= u"HollowMike";  //  2 bytes

    const char32_t* name3= U"HollowMike";  // 4 bytes

    std::cout << name0 << std::endl;
    std::wcout << name1 << std::endl;

    // these need special syntax for printing the strings, otherwise they are 
    // just printing the address
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;
}