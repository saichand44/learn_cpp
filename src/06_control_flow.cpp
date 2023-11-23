#include <iostream>
#include "../include/log.h"

int main()
{
    for (int i = 0; i< 5; i++)
    {   
        if (i % 2 == 0)
        {   
            // This statement will take the loop to next iteration without further
            // proceeding to the next steps. In this case, the print statements
            // are skipped when the reminder is 0 and the loop reached the start
            continue;
        }
        Log("Hello World!");
        std::cout << i << std::endl;
    }

    for (int i = 0; i< 5; i++)
    {   
        if (i > 2)
        {   
            // This statement will stop the loop from further proceeding and 
            // stop the iterations whenever "break" is triggered. We will come out
            // of the loop.
            break;
        }
        Log("Hello World!");
        std::cout << i << std::endl;
    }
}