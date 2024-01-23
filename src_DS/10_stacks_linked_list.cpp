#include <iostream>

// Here we implement "stacks" using linked lists! Stacks are abstract data types.
// Since the requirement for the stack operations like insertion and delection 
// should be in O(1), we perform the operation at the head as adding/removing 
// nodes at the head is O(1). 

// Adding or removing at the tail is O(n). Is there a work around to make it look
// like O(1) ?? --> [NEED TO LOOK INTO THIS]

struct node
{
    int data;
    node* next;
};

void push(int x, node* &top)
{
    // add element at the top to the array
    node* newNode = new node();
    newNode->data = x;
    
    // reassign address such that the top points to the new node and the new node
    // points to NULL or another node
    newNode->next = top;
    top = newNode;
}

void pop(node* &top)
{
    // remove the element from the array

    // check if the list is empty
    if (top == NULL)
    {
        std::cout << "Error: Stack is empty" << std::endl;
        return;
    }

    node* temp = new node();
    temp = top;
    top = top->next;
    delete temp;
}

void Print(node* top)
{
    node* temp = new node();
    temp = top;

    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{   
    node* top = NULL;

    push(2, top);Print(top);
    push(5, top);Print(top);
    push(10, top);Print(top);
    pop(top);Print(top);
    push(12, top);Print(top);
}