#include <iostream>

/*
Here we are implementing a method to delete a node in the BST. We will have three
cases in this situation. The node to be deleted can have a) no children 
b) one child and c) two children.

a) No children: In this case, we are essentially deleting a leaf node and hence
all we have to do is just delete the node and assign "NULL" to it's parent node
left or right depending on which side the leaf node is

b) One child: In this case, we just have to delete the node and connect its 
parent and child. 

c) Two children: In this case, we first have to replace the existing node with
either the max value in the left sub-tree or min value in the right sub-tree. THis
is followed by deleting the node itself. This method ensures that the property of
BST is still obeyed.
*/

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* generateNode(int data)
{   
    // create a BST Node
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

// using interations method
int findMin_loop(BSTNode* root)
{
    // check if the tree is empty
    if (root == NULL)
    {
        std::cout << "Binary Search Tree is empty!!" << std::endl;
        return -1;
    }

    else
    {
        while(root->left != NULL)
        {
            root = root->left;
        }

        return root->data;
    }
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
    else if (root->data > data)
    {
        return searchBST(root->left, data);
    }
    else
    {
        return searchBST(root->right, data);
    }
}

BSTNode* deleteNode(BSTNode* root, int data)
{
    // check if the BST is empty
    if (root == NULL)
    {
        return root;
    }

    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }

    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }

    else // found the node to be deleted
    {
        // case 1 (no children):
        if (root->left == NULL && root->right == NULL)
        {   
            delete root;

            // setting the left / right node of parent attached to current node
            root == NULL;
        }

        // case 2 (one child):
        else if (root->left == NULL)
        {
            BSTNode* tempNode = root;
            
            // setting the left / right node of parent attached to right child node
            root = root->right;

            delete tempNode;
        }

        else if (root->right == NULL)
        {
            BSTNode* tempNode = root;
            
            // setting the left / right node of parent attached to left child node
            root = root->left;
             
            delete tempNode;
        }

        // case 3 (two children):
        else
        {
            int minData = findMin_loop(root->right);

            // update the data in the root to be the min value in right sub-tree
            // or the max value in left sub-tree
            root->data = minData;

            // proceed to delete the node corresponding to minData in righ sub-tree
            root->right = deleteNode(root->right, minData);
        }
    }

    return root;
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

    searchBST(root, 12);
    root = deleteNode(root, 12);
    searchBST(root, 12);
}