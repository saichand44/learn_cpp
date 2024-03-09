#include <iostream>

/*
Here we are implmenting a method ot fins the minimum and maximum elements in a
binary search tree. We will use two methods. 1) Using loops / iterations and
2) Using recursion. One thing to remember is that, in BST, the smaller values are
on the left side and higher values are on the right side.


For min. value, all we need to do is to keep searching in the left side of the
tree until we find a node which has no further children. Similar stratergy for 
finding the maximum value. 
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

// using recursive method
int findMax_recursion(BSTNode* root)
{
    // check if the tree is empty
    if (root == NULL)
    {
        std::cout << "Binary Search Tree is empty!!" << std::endl;
        return -1;
    }

    else if (root->right == NULL)
    {
        return root->data;
    }

    else
    {   
        // search in the right sub tree
        return findMax_recursion(root->right);
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

    std::cout << findMin_loop(root) << std::endl;
    std::cout << findMax_recursion(root) << std::endl;
}