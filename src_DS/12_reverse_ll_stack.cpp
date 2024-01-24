#include <iostream>
#include <stack>

// Here we are reversing the linked list using the stack. In the stack, we will
// store the addresses of the nodes and the last node will be the first element
// in the stack after pushing all nodes. Then we use a temp node that traverses 
// the linked list from the tail end to the start end.

struct node
{
    int data;
    node* next;
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

void Reverse(node* &head)
{   
    // if the linked list is empty
    if (head == NULL)
    {
        return;
    }

    std::stack<node*> S;
    node* temp = head;

    // push the address of the nodes to the stack
    while(temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }

    // reverse the links
    temp = S.top();
    head = temp;
    S.pop();           // remove the top-most element

    while(!S.empty())
    {   
        // redirect the temp node to the top node which is the node before since
        // we used pop before
        temp->next = S.top();     

        S.pop();               // remove the top-most element of the stack

        // update the temp node to the node before
        temp = temp->next;
    }

    temp->next = NULL;       // for handling the condition when the temp node reaches end
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

    Reverse(head);
    print(head);
}