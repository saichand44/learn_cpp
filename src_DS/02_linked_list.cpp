#include <iostream>

// INSERTING A NODE AT THE BEGINNING OF THE LIST

// define the node definition
struct node
{
    int data;    // data type depends on the type of data we want to store
    node* next;  // pointer to the next node
};

node* insert(int x, node* head)
{   
    //NOTE: Here since we are passing the variables in the fucntion, we just create
    // copies of the variables passed. This means that we create a copy of the 
    // "head" pointer and then do the modifications. So we are technically changing 
    // the contents of the copy. If we don't return the updated "head", we are just
    // modifying the copy of "head" within this fucntion and nothing else!!

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c

    // insert a node at the beginning of the list
    node* temp = new node();
    temp->data = x;           // assign the given data to the temp node
    temp->next = head;        // assign the address of the "previous first" node to temp
    head = temp;              // update the head to point to the newly added node

    return head;
}

void insertByRef1(int x, node** pointerToHead)
{   
    //NOTE: Pass by reference avoids the issues stated in the previous function
    // as we are directly modifying the contents at the address of the head rather than
    // the copy 

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c

    // In this case, we are using pointer to pointer

    // insert a node at the beginning of the list
    node* temp = new node();
    temp->data = x;                    // assign the given data to the temp node
    temp->next = *pointerToHead;       // assign the address of the "previous first" node to temp
    *pointerToHead = temp;             // update the head to point to the newly added node

}

void insertByRef2(int x, node* &head)
{   
    //NOTE: Pass by reference avoids the issues stated in the previous function
    // as we are directly modifying the contents at the address of the head rather than
    // the copy

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c
    
    // In this case, we are using pass by reference syntax sugar

    // insert a node at the beginning of the list
    node* temp = new node();
    temp->data = x;                    // assign the given data to the temp node
    temp->next = head;       // assign the address of the "previous first" node to temp
    head = temp;             // update the head to point to the newly added node

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
    node* head = NULL;    // initially the head is pointing to null pointer

    std::cout << "How many numbers?" << std::endl;

    int n, x;

    std::cin >> n;

    for (int i=0; i < n; i++)
    {
        std::cout << "Enter the number" << std::endl;
        std::cin >> x;

        // [METHOD 1]:
        // Here it is important to return "head" too than just inserting. If not,
        // the print function always refers to the intial initialization of "head" (NULL)
        // This is probably due to the compiler just smartly referring the "head"
        // in the code to NULL directly. So to avoid this, we need to manually pass
        // the updated "head"!! [since we are passing the pointer]
        head = insert(x, head);

        // [METHOD 2]:
        // Alteratively if we pass "head" by reference in "insert" fucntion, we
        // avoid the return
        // insertByRef1(x, &head);
        
        // [METHOD 3]:
        // Alternate to insertByRef1();
        // insertByRef2(x, head);

        print(head);
    }
}