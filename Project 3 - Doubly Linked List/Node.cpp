#include "Node.h"

Node::Node() : next(nullptr)
{
} // end default constructor

Node::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor

Node::Node(const ItemType& anItem, Node* nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} // end constructor

void Node::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

void Node::setNext(Node* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

ItemType Node::getItem() const
{
   return item;
} // end getItem

Node* Node::getNext() const
{
   return next;
} // end getNext
