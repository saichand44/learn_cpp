#include <iostream>

/*
Here we implement "queue" using arrays! Queue are abstract data types. It follows
the FIFO (first in first out) logic. Here we use the concept of circular arrays
which makes efficient use of the memory available while at the same time maintaining
the notion of front and tail of the queue.
*/

# define MAX_SIZE 101  // for the size of the circular array

class Queue
{
private:
    int A[MAX_SIZE];
    int front, rear;      // indices to represent the front and rear of queue

public:
    // deifne a constructor that gives default values to front and rear
    Queue()
        : front(-1), rear(-1)
    {
    }

    // check whether the queue is empty or not
    bool isEmpty()
    {
        if (front == -1 && rear == -1) return true;
        else return false;
    }

    // check whether the queue is full or not
    bool isFull()
    {
        if ((rear + 1)%MAX_SIZE == front) return true;
        else return false;
    }

    // insert elements to the queue
    void enqueue(int x)
    {
        std::cout << "Enqueuing " << x << std::endl;

        if (isFull())
        {
            std::cout << "[ERROR] Queue is full" << std::endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        // add the element to the array
        A[rear] = x;
    }

    // remove the element from the queue
    void dequeue()
    {
        std::cout << "Dequeuing..." << std::endl;

        if (isEmpty())
        {   
            std::cout << "[ERROR] Queue is empty" << std::endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    // returns the front of the queue
    int getFront()
    {
        if (front == -1)
        {
            std::cout << "[ERROR] Queue is empty" << std::endl;
            return -1;
        }
        else
        {
            return A[front];
        }
    }

    // print the queue
    void print()
    {
        // find the number of elements in the queue
        int count = (rear - front)%MAX_SIZE + 1;

        for (int i=0; i < count; i++)
        {   
            int index = (front + i) % MAX_SIZE;
            std::cout << A[index] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
   Queue Q; // creating an instance of Queue. 
   Q.enqueue(2);  Q.print();  
   Q.enqueue(4);  Q.print();  
   Q.enqueue(6);  Q.print();
   Q.dequeue();	  Q.print();
   Q.enqueue(8);  Q.print();
   std::cout << Q.getFront() << std::endl;
}