#include <iostream>

struct node
{   
    // "struct" that contains the data as well as a pointer to the next node

    int data;      // data type depends on the type of data we want to store
    node* next;    // pointer to the next node
};

int main()
{

    // define a head to store the address of the first node
    node* head;
    head = NULL;    // initially the head is pointing to null pointer

    // create a first node and then assign it's address to the head
    // temp node will be the intermediate node that is useful in linking
    node* temp = new node();    // creating a node in heap memory (new --> returns pointer)

    // add the first node
    temp->data = 5;     // update data of node "struct" using arrow operator
    temp->next = NULL;  // assign null pointer to the pointer of temp 
    head = temp;        // redirect head to the address of next node

    // add another node
    node* temp1 = new node();
    temp1->data = 10;
    temp1->next = NULL;
    temp->next = temp1;

    // we can check if the linking has been correctly done or not
    // "temp->next->next" should be pointing to null pointer!
    std::cout << temp->next->next << std::endl;
    
}