#include <iostream>

// DOUBLY LINKED LIST
// a) INSERT NODES AT THE HEAD AND TAIL
// b) PRINT (FORWARD, BACKWARD)

// define the node definition
struct node
{
    int data;    // data type depends on the type of data we want to store
    node* next;  // pointer to the next node
    node* prev;  // pointer to the previous node
};

node* getNewNode(int x)
{
    // create and return the address of the new node by taking in the data field
    // This function creates the new node in the heap memory.
    node* newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

    // We can also create the new node in the stack memory. We just have to return
    // the address of the new node manually in that case.
    // node newNode;
    // newNode.data = x;
    // newNode.next = NULL;
    // newNode.prev = NULL;
    // return &newNode;
}

void insertAtHead(int x, node* &head)
{
    // Insert the new node before the head node. Two cases are possible, list can 
    // be empty and non-empty.

    node* newNode = getNewNode(x);

    // if the list in empty
    if (head == NULL)
    {
        head = newNode;
    }

    // if the list is non empty, add the new node before the head node
    else
    {
        head->prev = newNode;   // first, point the head node's prev pointer to new node
        newNode->next = head;   // second, point the new node's next pointer to head node
        head = newNode;         // third, update the pointer to the head to new node
    }
}

void forwardPrint(node* head)
{   
    // print the list in the forward direction
    node* temp = head;

    std::cout << "Forward: ";
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void reversePrint(node* head)
{   
    // print the list in the reverse direction. Here the we will first traverse to
    // the last node and we can use the prev node pointer to traverse the list
    // in the reverse direction.

    node* temp = head;

    // traverse to the end of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // start from the last node and traverse backward
    std::cout << "Reverse: ";
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}

void insertAtTail(int x, node* &head)
{
    // Insert the new node after the tail node. Since we are talking about tail node,
    // we are assuming that the list is non-empty

    // Here the we will first traverse to the last node and we can use the next node pointer
    // to add the new node to end of the list
    node* newNode = getNewNode(x);
    node* temp = head;

    // traverse to the end of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{   
    node* head = NULL;
    insertAtHead(2, head); forwardPrint(head); reversePrint(head);
    insertAtHead(4, head); forwardPrint(head); reversePrint(head);
    insertAtHead(8, head); forwardPrint(head); reversePrint(head);
    insertAtHead(16, head); forwardPrint(head); reversePrint(head);

}