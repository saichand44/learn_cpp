#include <iostream>

/*
Here we will find the height if the tree. 

1. Height of a node = Number of edges along the longest path from that node 
                      to the leaf node
2. Height of a tree = Height of a root node
3. Depth of a node  = Number of edges in the path from the root node to that 
                      particular node

Height and Depth of a node need not be same. 
Ex: Height of a leaf node = 0 but the depth of a leaf node will be > 0 (for non empty tree)
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
    else if (data <= root->data)
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

int findHeight(BSTNode* root)
{
    /*
    Here we recursively get the height of the left and the right sub trees 
    and get the maximum of the two. In the end we add the previous stated value
    by 1 to account for the edge connecting the left or right sub tree.
    */

   if (root == NULL)
   {
        return -1;
   }

   return std::max(findHeight(root->left), findHeight(root->right)) + 1;
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

    std::cout << "Height of the tree: " << findHeight(root) << std::endl;
}