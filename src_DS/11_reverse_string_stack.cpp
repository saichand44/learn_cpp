#include <iostream>
#include <stack> // stack from standard template library
#include <string.h>

// Here we are reversing a string using a stack. In stack, we have "Last in First out"
// So we will take in the characters of the string and push them to the stack and
// then access the characters one by one and rewrite the string. Since the last
// added char is the first one to come out, we will have the string reversed!

void Reverse(char C[], int n)
{
    // This fucntion reverses the character
    // Since for the arrays, C[] is basically the address to the first element,
    // we are directly modifying the array rather than its copy

    std::stack<char> S;

    // loop through the char array and push to stack
    for (int i=0; i < n; i++)
    {
        S.push(C[i]);
    }

    // loop through the elements of the stack and rewrite the array
    for (int i=0; i < n; i++)
    {
        C[i] = S.top();  // access the top element of the stack
        S.pop();         // pop the lastest element in the stack
    }
}

int main()
{
    char C[51];
    std::cout << "Enter the string: ";
    std::cin >> C;

    Reverse(C, strlen(C));
    std::cout << "Output: " << C << std::endl;
}