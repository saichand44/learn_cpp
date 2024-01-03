#include <iostream>

// INSERTING A NODE AT THE N-TH POSITION OF THE LIST

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

void print(node* head)
{
    // print the list as we keep adding the nodes / data
    std::cout << "List: ";
    while(head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;    // switch to the next node
    }
    std::cout << std::endl;
}

int main()
{
    node* head = NULL;       // empty list
    insert(2, 1, head);      // list: 2
    insert(3, 2, head);      // list: 2 3
    insert(4, 1, head);      // list: 4 2 3
    insert(6, 2, head);      // list: 4 6 2 3
    print(head);
}