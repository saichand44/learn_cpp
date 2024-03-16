#include <iostream>
#include <queue> // standard C++ library for queue

/*
Here we are implementing the binary tree traversal usng the "Breadth First" approach.
We traverse through the nodes that are in the same level / depth (left to right)
and then move to a higher depth. 

The key here is to not vist the a node more than once, so backtracking is not an
option (as we don't have backward reference anyway from children to parent). 
So we use "queue" where we enqueue the node first and before dequeuing it, we
enqueue it corresponding children.

* Time Complexity = O(n) since we have to go through all the nodes
* Space Complexity
    a) best case: all the nodes are left or right --> O(1). Since at any given time
    we will add the children (1) and remove the parent(1) at a time
    b) worst case:  perfect binary tree --> O(n). Since in the worst case, when
    we are above the deepest level, the queue will have all the cildren of the 
    (depth-1) level (i.e. n/2 children). So the space complexity is O(n/2) ~ O(n)
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

void levelOrder(BSTNode* root)
{
    // check if the tree is empty
    if (root == NULL)
    {
        std::cout << "Binary Search Tree is empty!!" << std::endl;
        return;
    }

    std::queue<BSTNode*> Q;

    // push the root node
    Q.push(root);

    while(!Q.empty())
    {
        BSTNode* currNode = Q.front();

        // print the data from traversal
        std::cout << currNode->data << " ";

        if (currNode->left != NULL) Q.push(currNode->left);
        if (currNode->right != NULL) Q.push(currNode->right);

        // remove the current node (at the front) from the queue
        Q.pop();
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

    levelOrder(root);
}