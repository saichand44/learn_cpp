#include <iostream>

// Here we implement "stacks" using arrays! Stacks are abstract data types.
// If the array is maxed out in terms of size, then we have to use dynamic arrays
// where we create a new array that is "double" the sized of the previous array
// and copy the old content and new content to the newly created arrays

#define MAX_SIZE 101   // define maximum size of the array
int A[MAX_SIZE];       // initialize the array of int data type
int topIdx = -1 ;      // initialize the variable "topIdx" which always points to end of stack

void push(int x)
{
    // add element at the top to the array

    // check if addition of elements is possible i.e. array is full
    if (topIdx == MAX_SIZE-1)
    {
        std::cout << "Error: Stack Overflow" << std::endl;
        return;
    }

    A[++topIdx] = x;    // do a post increment to the top index and then add element
}

void pop()
{   
    // remove the element from the array

    // check if the list is empty
    if (topIdx == -1)
    {
        std::cout << "Error: Stack is empty" << std::endl;
        return;
    }

    // just update the index of the top by decrementing it
    topIdx--;
}

int top()
{
    // return the element at the top position
    return A[topIdx];
}

void Print()
{
    // print the elements in the stack
    std::cout << "Stack: ";
    for (int i = 0; i <= topIdx; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    push(2);Print();
    push(5);Print();
    push(10);Print();
    pop();Print();
    push(12);Print();
    std::cout << top() << std::endl;
}