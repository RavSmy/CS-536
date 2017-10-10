#ifndef NODE_
#define NODE_

#include <string>
using namespace std;

typedef string ItemType;

class Node
{
private:
	ItemType  item;  // A data item
	Node*	  prev;  // Pointer to prev node
	Node*     next;  // Pointer to next node

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node* nextNodePtr);
	void setPrev(Node* nextNodePtr);
	ItemType getItem() const;
	Node* getNext() const;
	Node* getPrev() const;
}; // end Node

#endif