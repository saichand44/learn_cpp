#include <iostream>
// These are preprocessor statements. This bascially copies the entire content 
// of the include files and pastes in the current file

// The main function is an exception that it takes "int" as the return type for 
// the function.

// std is a namespace and it has the some standard fucntions like cin and cout
// avoid using "using namespace std" as it can cause some issues / ambiguities
// with some variable names that are already present in the std namespace and
// and that we define in the code (as variables).
// using count as local variable when using "using namespace std" can cause issues
// as std as a variable with name as count already!!


int main()
{
    std::cout << "Hello World!!" << std::endl;
}