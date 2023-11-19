#include <iostream>
//header files - similar to the preprcessor statements like iostream, we use
// #include and it literally copy pastes the content in the header files to the
// current code

// Here <> brackets are used instead of the "", as this is just saying the compiler
// to include the files that are in the include path list (similar to sys path in
// python). This is used for standard include files. Also C++ standard header
// files do not have the extension ".h" but C standard header files do! (like stdlib.h)

#include "../include/log.h"
// Here "" are used instead of the <> brackets as we are saying the compiler to
// include the files that are in the desired (current / relative) folder. Using
// the entire relative path might not be entirely necessary as we can just write
// instructions to cmake where to search for the header files. In this case, 
// we are using the default compiler instrcutions from vscode, so included the 
// relative path

int main()
{
    Log("Hello World!!");
}