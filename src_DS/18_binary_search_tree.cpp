# include <iostream>
#include <iomanip>

/*
Here we are implementing the binary search tree using doubly linked list. In binary
search trees, the data of nodes on left is <= to the data of the nodes on the right
side.

For inserting a new data into the tree, we first compare the new value with the
data of th nodes and accordingly decide whether to put it on left or right side.
For both inserting and searching the tree, we will use recursion.

In case of balanced binary trees, the typical time complexity is O(logn) [log with base 2]
In worst case i.e. for unbalanced binary tree, the time complexity is O(n)
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
    // create a BST node
    BSTNode* newNode = new BSTNode();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BSTNode* insert(BSTNode* &root, int data)
{
    //NOTE: Pass by reference avoids the issues stated in 02_linked_list.cpp
    // as we are directly modifying the contents at the address of the head rather than
    // the copy

    // REF:https://kevin-yang.medium.com/c-pass-by-value-pointer-reference-ddc3780d907c
    
    // In this case, we are using pass by reference syntax sugar

    BSTNode* newNode = generateNode(data);

    // check if the BST in empty
    if (root == NULL)
    {
        root = newNode;
    }

    // check if the new data is <= to the root node data
    else if (root->data <= data)
    {
        root->left = insert(root->left, data);
    }

    // check if the new data is >= to the root node data
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void searchBST(BSTNode* root, int data)
{
    // check if the BST is empty or data not found
    if (root == NULL)
    {
        std::cout << "Not Found!" <<std::endl;
        return;
    }

    else if (root->data == data) std::cout << "Found!" <<std::endl;
    else if (root->data <= data)
    {
        return searchBST(root->left, data);
    }
    else
    {
        return searchBST(root->right, data);
    }
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

    int queryNum;
    std::cout << "Enter the number for query:"; 
    std::cin >> queryNum;
    searchBST(root, queryNum);
}