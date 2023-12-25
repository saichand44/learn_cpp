#include <iostream>

// arrays are basically a bunch of variables that are grouped together with
// the same data type. It is easier to use arrays as we can use for loop to 
// access or assign values to the variables of the array. Otherwise, we have to
// define the variables individually and change all those individually which is a
// tidious task!

// Arrays are contiguious memory and are basically pointers. The name of the 
// array is the pointer referring to the address of the first element. 

// The different variables within the array are accessed using indexing.


// NOTE: we can define arrays in both heap and stack but if we define in 
// heap memory, then we also need to take care of deleting the memory as well

int main()
{
    int example[5];
    example[0]=2;
    example[4]=2;

    std::cout << example[0] << std::endl;
    std::cout << example[4] << std::endl;
    std::cout << example << std::endl;   // prints the memory address of the first
                                         // element of the array

    // we can use for loop to assign or access the elements
    for (int i =0 ; i < 5; i++)   // Here we use the "<" operator with i < 5 instead
    {                             // of "<=" with i <=4 since the former is 
                                  // computationally more efficeint as it does only
                                  // check of "<" (one) instead of "<="(two) comparision checks
    example[i]=i;
    }                             
    
    // arrays and pointers
    int* arrayPtr = example;

    // both these access the same memory address. In case ot pointers, since just
    // have to traverse from the stating memory address by two memory size of "int"
    // and then derefernce it to get the variable. We can also traverse by "1 byte"
    // if we deinfe the pointer with data type "char" but then we need to know 
    // size of "int" on that machine
    std::cout << "Arrays and Pointers" << std::endl;
    std::cout << example[4] << ";" << *(arrayPtr+4) << std::endl;

    // here we are accessing the address in steps on 1 byte!
    std::cout << *(int*)((char*)arrayPtr+16) << std::endl; 

}