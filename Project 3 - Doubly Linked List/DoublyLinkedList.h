#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include "LinkedList.h"
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
    DoublyLinkedList(const DoublyLinkedList &obj); // Deep copy constructor
    DoublyLinkedList(const LinkedList &obj); // LL to DLL

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
    void reverse(); 

	ItemType getEntry(int position) const;

	ItemType replace(int position, const ItemType& newEntry);

	virtual ~DoublyLinkedList();
}; // end ArrayList

#endif -
