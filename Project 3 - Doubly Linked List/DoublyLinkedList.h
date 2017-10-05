#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include <string>
using namespace std;

typedef char ItemType;

class DoublyLinkedList
{
private:
	Node* headPtr; 	// Pointer to first node in the chain
	Node* tailPtr;  // Pointer to the last node in the chain
	int itemCount;   // Current count of list items 

					 // Locates a specified node in this doubly linked list
	Node* getNodeAt(int position) const;

public:
	DoublyLinkedList();
	// Copy constructor and destructor are supplied by compiler

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	ItemType getEntry(int position) const;

	ItemType replace(int position, const ItemType& newEntry);

	virtual ~DoublyLinkedList();
}; // end ArrayList

#endif 
