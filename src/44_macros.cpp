/*
Usually before compilation, there is a preprocessor that goes through the entire
code and gives instructions to the compiler to preprocess or include some information.
#include is a preprocessor that literally copies the content of that header file
and pastes it in the current cpp file. 

During this preprocessor stage, macros enable us to literally substitute a text
with its corresponding piece of code / constant..etc.

Don't define marcos in another file and use that macro in the current file as it 
can lead to confusions to the reader. Also only use macros when here is a 
absolute neccessity of it.
*/

#include <iostream>

#define DEBUG_MODE 1   // using a macro to replace a text with constant 

// Here we are using a macro to replace text "LOG(x), x = argument" with a piece
// of code. Macros to replace code can be useful in this kind of scenario where
// we might want some information to be logged during debugging but in the release
// mode we don't need that as it is not required. Note the syntax for if, else
// in the preprocessor stage!!

// Also be careful with using ";" twice, one at macro definition and other in the
// actual code.

#if DEBUG_MODE == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

int main()
{
    LOG("Hello");
}


