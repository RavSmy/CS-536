#include "BTNode.h"
#include <iostream>

using namespace std;


int getHeight(BTNode* root)
{
    if (root == NULL) return 0;
    
    int heightLeft = getHeight(root->getLeft());
    int heightRight = getHeight(root->getRight());
    
    return 1 + std::max(heightLeft, heightRight);    
}

int getNumNodes(BTNode* root)
{
    if (root == NULL) return 0;
    return 1 + getNumNodes(root->getLeft()) + getNumNodes(root->getRight());
}

void inOrder(BTNode* root)
{
    if (root != NULL)
    {
        inOrder(root->getLeft());
        cout << root->getItem() << " ";
        inOrder(root->getRight());
    }   
}

void postOrder(BTNode* root)
{
    if (root != NULL)
    {
        postOrder(root->getLeft());
        postOrder(root->getRight());
        cout << root->getItem() << " ";

    }   
}

int main()
{
    // Build a sample tree by brute force
    //          A
    //       B     C
    //     D   E      F
    //
    
    BTNode* b = new BTNode('B');
    BTNode* c = new BTNode('C');
    BTNode* d = new BTNode('D');
    BTNode* e = new BTNode('E');
    BTNode* f = new BTNode('F');
    
    BTNode* root = new BTNode('A', b, c);
    b->setLeft(d);
    b->setRight(e);
    c->setRight(f);
    
    // Get Height and Number of Nodes
    cout << "Height: " << getHeight(root) << "  Num Nodes: " << getNumNodes(root) << endl;
    
    // InOrder Traversal
    cout << "InOrder: ";
    inOrder(root); 
    cout << endl;
    
    // PostOrder Traversal
    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;
}
