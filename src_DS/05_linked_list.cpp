#include <iostream>

// REVERSE A LINKED LIST [REVERSE THE LINKS OF THE NODES]

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

void reverse(node* &head)
{
    // Here we traverse the linked list and keep on updating the address field 
    // of the node to previous node intead of next node. For this we need two
    // pointer variables, prevNode and nextNode. We will do this in a loop until
    // we reach NULL / end of list and finally assign the last address field to
    // head!

    // Here while defining multiple pointers in a single line, the "*" should be
    // accompained to the variable rather than data type. If we do it at datatype
    // the pointer is assigned only to first variable and the rest are just normal
    // variables!
    node *prevNode, *currNode, *nextNode;
    currNode = head;
    prevNode = NULL;

    while(currNode != NULL)
    {
        nextNode = currNode->next; // capture the next node address
        currNode->next = prevNode; // update the address field in current node to previous node
        prevNode = currNode;       // move forward the previous node to current node location   
        currNode = nextNode;       // move forward the current node to next node location  
    }
    head = prevNode;               // assign the head to the last node address
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
    insert(5, 1, head);      // list: 5 2 3
    insert(6, 2, head);      // list: 5 6 2 3
    print(head);

    std::cin.get();          // wait until the user permits before reversing
    reverse(head);
    print(head);
}