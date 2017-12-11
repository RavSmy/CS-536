#include "BTNode.h"

BTNode::BTNode(char theItem) : item(theItem), left(NULL), right(NULL)
{
}

BTNode::BTNode(char theItem, BTNode* l, BTNode* r) : item(theItem), left(l), right(r)
{
}
       
void BTNode::setItem(char theItem)
{
    item = theItem;
}

char BTNode::getItem()
{
    return item;
}
        
void BTNode::setLeft(BTNode* l)
{
    left = l;
}

BTNode* BTNode::getLeft()
{
    return left;
}

void BTNode::setRight(BTNode* r)
{
    right = r;
}

BTNode* BTNode::getRight()
{
    return right;
}

bool BTNode::isLeaf()
{
    return left == NULL && right== NULL;
}
