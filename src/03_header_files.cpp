#include <iostream>
//header files - similar to the preprcessor statements like iostream, we use
// #include and it literally copy pastes the content in the header files to the
// current code

// Here <> brackets are used instead of the "", as this is just saying the compiler
// to include the files that are in the include path list (similar to sys path in
// python). This is sued for standard include files. Also C++ standard header
// files do not have the extension ".h" but C standard header files do! (like stdlib.h)

#include "../include/log.h"
// Here "" are used instead of the <> brackets as we are saying the compuler to
// includes the files that are in the desired (current / relative) folder

int main()
{
    Log("Hello World!!");
}