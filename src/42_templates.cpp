/*
Templates in C++ are literally like templates to do something. They provide a
generic and reusable code that enables classes and fucntions to operate with
different data types.

If there is a print function that takes in an argument to print. If the argument
is an 'int' type, then if we pass in a type like string in that print function,
it will throw an error because of the argument datatype mismatch. To avoid this, 
we can write another overloaded function that accepts datatype string. This whole
process is not tidy and not efficient if we have to make changes in the fucntion 
as we have to modify all the functions. This is where templates are very useful.

Another good thing about templates are that compiler convert them to machine
code only wher they are invoked like in main(). Otherwise, the compiler ignores
their compilation and even if the functions/classes in templates have syntax 
errors, we don't get compilation errors in such case.

If we just have a function, they are always converted to machine code unlike templates.
*/

#include <iostream>
#include <string.h>

template<typename T> //'typename/class' to specify the type of template parameter, T=type
void print(T value)
{
    std::cout << value << std::endl;
}

// Below we are creating an array of the desired datatype and size during the call
// As we can see it is pretty generic as we can create an array of any datatype and
// size
template<typename T, int size> 
class Array
{
private:
    T m_array[size];
public:
    int get_size() const
    {   
        size_t array_len = sizeof(m_array) / sizeof(m_array[0]);
        return array_len;
    }
};

int main()
{   
    // using the datatype is optional as compiler can automatically get the datatype
    print<int>(5);                  
    print<std::string>("Hello!");

    Array<int, 50> array;
    std::cout << array.get_size() << std::endl;
}