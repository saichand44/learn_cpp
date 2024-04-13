#include <iostream>
#include <limits> // to define the infinite bounds

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()

/*
In this we implement code to check if a binary tree is a binary search tree. In
binary tree, each node has at most two children and in binary search tree, we 
have a specific pattern where the values on the left subtree are lesser than the 
values on the right subtree.

We can implement this using two approaches. One where we traverse through the nodes
everytime in the recursion and other where we check for the nodes if their values
fall in between certain bounds (this will be a constant time execution).
*/

/*
Construct the binary tree
*/
struct BSTNode
{
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

/*
METHOD 1:
In this case, we tree every sub tree as another binary tree and use recursion to
check if each sub tree is a BST. The downside of this method is we traverse
through the same set of nodes multiple times at different stages of sub-tree
checks
*/
bool isSubtreeLesser1(BSTNode* root, int value)
{   
    // check if we reached the end of the subtree
    if (root == NULL) return true;

    // check the left and right sub trees of sub tree have nodes less than the 'value'
    if (root->data <= value &&
        isSubtreeLesser1(root->left, value) &&
        isSubtreeLesser1(root->right, value))
    {
        return true;
    }

    else return false;
}

bool isSubtreeGreater1(BSTNode* root, int value)
{
    // check if we reached the end of the subtree
    if (root == NULL) return true;

    // check the left and right sub trees of sub tree have nodes grater than the 'value'
    if (root->data > value &&
        isSubtreeGreater1(root->left, value) &&
        isSubtreeGreater1(root->right, value))
    {
        return true;
    }

    else return false;
}

bool isBinarySearchTree1(BSTNode* root)
{
    // check if the tree is empty
    if (root ==NULL) return true;

    if (isSubtreeLesser1(root->left, root->data) &&
        isSubtreeGreater1(root->right, root->data) &&
        isBinarySearchTree1(root->left) &&
        isBinarySearchTree1(root->right))
    {
        return true;
    }

    else return false;
}

/*
METHOD 2:
In this case, we start with a range within which the root node data has to be 
bounded. Now as we traverese through depth (for other sub trees), we dynamically
update the min and max bounds that the root nodes of those sub trees has to obey.
This is an efficient implementation as the comparision within min, max values is 
a constant time operation.

The very first node / root node starts with a min and max bound as -inf and +inf
Reference: 
*/
bool isBinarySearchTree2(BSTNode* root, int minValue, int maxValue)
{
    // check if the tree is empty
    if (root == NULL) return true;

    if (root->data > minValue &&
        root->data < maxValue &&
        isBinarySearchTree2(root->left, minValue, root->data) &&
        isBinarySearchTree2(root->right, root->data, maxValue))
    {
        return true;
    }

    else return false;
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

    // check using method 1
    std::cout << "Is it a BST: " << isBinarySearchTree1(root) << std::endl;

    // check using method 2
    std::cout << "Is it a BST: " << isBinarySearchTree2(root, INT_MIN, INT_MAX) << std::endl;
}