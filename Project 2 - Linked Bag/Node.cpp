// CS 536, PROJECT 2 (Node.cpp), Ravela Smyth 

#include "Node.h"

Node::Node() : next(NULL)
{
} // end default constructor

Node::Node(const ItemType& anItem) : item(anItem), next(NULL)
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
