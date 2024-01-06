#include <iostream>

// PRINT THE REVERSE ORDER A LINKED LIST ["NO" REVERSING THE LINKS OF THE NODES]
// USING RECURSION

// define the node definition
struct node
{
    int data;    // data type depends on the type of data we want to store
    node* next;  // pointer to the next node
};

void insert(int data, int position, node* &head)
{   
    //NOTE: Pass by reference avoids the issues stated in 02_linked_list.cpp
    // as we are directly modifying the contents at the address of the head rather than
    // the copy

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c
    
    // In this case, we are using pass by reference syntax sugar

    // create a node using temp1
    node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;

    if (position == 1)  // special case to handle adding node at the beginning
    {
        temp1->next = head;
        head = temp1;
    }

    else              // to handle node instertion at any location expect 1
    {
        // use this temp2 variable to tranverse through the list and stop at n-1 node
        node* temp2 = head;

        //position-2 because we are starting at head and we need to stop at n-1 node
        for (int i=0; i < position-2; i++)
        {
            temp2 = temp2->next;
        } // This loop finishes at the n-1 th node

        // link the temp1 node (n th node) to the temp2 node (n-1)
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}

void printList(node* node)
{
    // Here we are using recursion to print the list in the forward direction

    // exit condition for the linked list
    if (node == NULL)
    {
        return;
    }

    // We first print the data at the node and then invoke the recursive call
    // which basically traverses through the entire list until it reached NULL

    std::cout << node->data << " ";      // print the value in the node
    printList(node->next);               // recursive call which passed next node as argument
}

void reversePrintList(node* node)
{
    // Here we are using recursion to print the list in the forward direction

    // exit condition for the linked list
    if (node == NULL)
    {
        return;
    }

    // We first invoke the recursive call which basically traverses through the 
    // entire list until it reached NULL and then call the print statement. This
    // basically starts printing the data in the reverse order

    reversePrintList(node->next);        // recursive call which passed next node as argument
    std::cout << node->data << " ";      // print the value in the node
}


int main()
{
    node* head = NULL;       // empty list
    insert(2, 1, head);      // list: 2
    insert(3, 2, head);      // list: 2 3
    insert(5, 1, head);      // list: 5 2 3
    insert(6, 2, head);      // list: 5 6 2 3

    printList(head);
    std::cout << std::endl;
    reversePrintList(head);
}