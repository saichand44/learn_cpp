#include <iostream>

/*
Here we implement "queue" using linked lists! Queue are abstract data types. It follows
the FIFO (first in first out) logic.

Here we will have two pointers that will keep track of address of the starting node
and the last node and can perform enqueue (push) or dequeue (pop) with time 
complexity of O(1). 

In this case, enqueue is done from last node and dequeue is done from the first
node.
*/

struct node
{
    int data;
    node* next;
};

void enqueue(node* &front, node* &rear, int x)
{
    //NOTE: Pass by reference avoids the issues of modifying copies instead of original
    // as we are directly modifying the contents at the address of the actual variable
    // rather than the copy

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c
    
    // In this case, we are using pass by reference syntax sugar

    // ADD ELEMENTS TO THE QUEUE

    // create a temp node that stores the address of the last node
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;

    // check the queue is empty
    if (front == NULL && rear == NULL)
    {
        rear = temp;
        front = rear;   // both front and rear pointing to the same first node
    }
    else
    {
        rear->next = temp;   // ensure the last node is pointing to the newly added node
        rear = temp;         // shift the rear node to the end of the list
    }
}

void dequeue(node* &front, node* &rear)
{
    // REMOPVE ELEMENTS FROM THE FRONT / START OF LIST

    // create a temp node
    node* temp = front;

    // check if the queue is empty
    if(front == NULL && rear == NULL)
    {
        std::cout << "[ERROR] Queue is empty!" << std::endl;
        return;
    }

    // when there is only one element in the queue
    else if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }

    else
    {
        front = front->next;
    }

    // delete the node that is not part of the queue anymore
    delete(temp);
}

int getFront(node* &front)
{
    // get the front of the queue
    if (front == NULL)
    {
        std::cout << "[ERROR] Queue is empty!" << std::endl;
        return 0;
    }
    else
    {
        return front->data;
    }
}

void printQueue(node* nodeInQueue)
{
    // print the queue using recursion method

    if (nodeInQueue == NULL)
    {
        std::cout << std::endl;
        return;
    }

    std::cout << nodeInQueue->data << " ";
    printQueue(nodeInQueue->next);
}

int main()
{   
    // create the front and rear nodes;
    node *front=NULL, *rear=NULL;

	enqueue(front, rear, 2); printQueue(front);
	enqueue(front, rear, 4); printQueue(front);
	enqueue(front, rear, 6); printQueue(front);
	dequeue(front, rear);  printQueue(front);
	enqueue(front, rear, 8); printQueue(front);
}