#include "Node.h"

Node::Node() : next(nullptr), prev(nullptr)
{
} // end default constructor

Node::Node(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
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

void Node::setPrev(Node* prevNodePtr)
{
	prev = prevNodePtr;
} // end setPrev


ItemType Node::getItem() const
{
	return item;
} // end getItem

Node* Node::getNext() const
{
	return next;
} // end getNext

Node* Node::getPrev() const
{
	return prev;
} // end getPrev