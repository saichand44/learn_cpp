#include <iostream>

// using the correct datatype is important for the function

int Multiply_type1(int a)
{
    // This function is defined as int data type but has the return values that
    // is a float since "5.1", so the end result is typecasted to int type and 
    //decimal values are remvoed. Just return the integer value
    return a*5.1f;
}

float Multiply_type2(int a)
{
    // This function is defined as float data type and has the result that is
    // returned of type float. So we get he output as float. Rememeber to use
    // "f" to strictly use float data type
    return a*5.1f;
}


int main()
{   
    std::cout << Multiply_type1(5) << std::endl;
    std::cout << Multiply_type2(5) << std::endl;

    // this line is optional as int main() is an expection for the data type and
    // it automatically assumes that we are returning 0 even if we didn't explicitly
    // specify this line!!
    return 0;
}
