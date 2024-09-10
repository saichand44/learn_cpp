#include <iostream>
#include <string.h>

/*
Usually in C++, we cannot straight forwardly return multiple variables of different
data types unlike in Python. There are several workarounds for the same in C++.

1. Using pass by reference or pointers
2. Using arrays or vectors --> limited to same datatype but multiple return values
    a. NOTE: In general when we create arrays and vectors, arrays are created in
             stack memory and vectors are created in heap memory.
3. Using a struct
4. Using tuple --> but this implemntation makes the code cluttered
*/

// MEHTOD 1:
void sum_and_string1(int &sum, std::string &string)
{
    // Modify the sum
    sum += 3;

    // Modify the string
    string[0] = '!';

    // Here we can also pass the variables using pointers instead of pass by reference
    // We just have to derefence in that case.
}

// METHOD 3:
struct multiple_return
{
    int sum;
    std::string string;
};

multiple_return sum_and_string2(int sum, std::string string)
{
    // Modify the sum
    sum += 3;

    // Modify the string
    string[0] = '!';

    return {sum, string};
}

int main()
{   
    int sum = 5;
    std::string string = "name";

    sum_and_string1(sum, string);
    std::cout << "Method 1 [OUTPUT]: " << sum << ", " << string << std::endl;

    multiple_return return_vars = sum_and_string2(sum, string);
    std::cout << "Method 3 [OUTPUT]: " << return_vars.sum << ", " << return_vars.string << std::endl;
}