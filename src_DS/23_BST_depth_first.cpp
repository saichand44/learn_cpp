#include <iostream>

/*
Here we are implementing the binary tree traversal using the "Depth First" approach.
We traverse through the nodes along the depth. Here we have three approaches. we
always visit the left sub-tree first before the right one (it is nor compulsory though)

1. Pre Order : Search direction <root><left><right>
2. In Order  : Search direction <left><root><right>
3. Post Order: Search direction <left><right><root>

* Time Complexity = O(n) since we have to go through all the nodes
* Space Complexity = O(height of tree) since we use recusion until the leaf node
                     and the worst case is starting from the root and till the 
                     leaf node and the recusion has functions ( = height of tree)
                     in the call-stack
*/

struct BSTNode
{
    // create a struct for node for of the binary search tree
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* generateNode(int data)
{
    BSTNode* newNode = new BSTNode();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void insert(BSTNode* &root, int data)
{
    //NOTE: Pass by reference avoids the issues stated in 02_linked_list.cpp
    // as we are directly modifying the contents at the address of the head rather than
    // the copy

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c
    
    // In this case, we are using pass by reference syntax sugar

    BSTNode* newNode = generateNode(data);

    // check if the BST is empty
    if (root == NULL)
    {
        root = newNode;
    }

    // check if the new data is <= to the root node data
    else if (data <= root->data)
    {
        insert(root->left, data);
    }

    // check if the new data is >= to the root node data
    else
    {
        insert(root->right, data);
    }
}

void preOrder(BSTNode* root)
{
    // traverse the binary search tree using depth first in <root><left><right>

    // exit condition for the recursion
    if (root == NULL) return;

    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BSTNode* root)
{
    // traverse the binary search tree using depth first in <left><root><right>

    // exit condition for the recursion
    if (root == NULL) return;

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BSTNode* root)
{
    // traverse the binary search tree using depth first in <left><right><root>

    // exit condition for the recursion
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}

int main()
{
    BSTNode* root = NULL;

    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 25);
    insert(root, 8);
    insert(root, 12);

    preOrder(root); std::cout << std::endl;
    inOrder(root); std::cout << std::endl;
    postOrder(root); std::cout << std::endl;
}