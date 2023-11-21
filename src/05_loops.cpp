#include <iostream>
#include "../include/log.h"

int main()
{
    for (int i = 0; i++ < 5;)
    // Here, the last entry for update is left intentionally to check other
    // behaviour (post increment vs preincrement)

    // When used i++ < 5, the value of i is updated after the comparision
    // When used ++i < 5, the value of i is updated before the comparision
    {
        Log("Hello World!");
        std::cout << i << std::endl;
    }

    // for loop is easier to access elements when using arrays and with iterable 'i'

    int i = 0;
    while(i < 5)
    {
        Log("Hey While Loop");
        i++;
    }

    // in do-while, the action is executed at least once before terminating as
    // the while loop is at the end rather than beginning.
    do
    {
        Log("Hey Do-While loop!");
    } while (0);
     
}