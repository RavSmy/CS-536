// CS 536, PROJECT 3, Ravela Smyth -- "DoublyLinkedList.cpp"

#include "DoublyLinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
}  // end default constructor


DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &obj) : itemCount(obj.itemCount)
{
	if (obj.headPtr == nullptr) {
		headPtr = nullptr;
	}
	else {
		headPtr = new Node(obj.headPtr->getItem());
		Node *currentObj = obj.headPtr;
		Node *current = headPtr;
		while (currentObj->getNext() != NULL)
		{
			current->setNext(new Node(currentObj->getNext()->getItem()));
			current->getNext()->setPrev(current);
			current = current->getNext();
			currentObj = currentObj->getNext();
		}	
		tailPtr = current->getPrev();
	}
} //end deep copy constructor

DoublyLinkedList::DoublyLinkedList(const LinkedList &obj) :itemCount(obj.getLength())
{
	if (obj.getHeadPtr() == nullptr) {
		headPtr = nullptr;
	}
	else {
		headPtr = new Node(obj.getHeadPtr()->getItem());
		Node *currentObj = obj.getHeadPtr();
		Node *current = headPtr;
		for (int i = 1; i < itemCount; i++)
		{
			current->setNext(new Node(obj.getEntry(i + 1)));
			current->getNext()->setPrev(current);
			current = current->getNext();
			currentObj = currentObj->getNext();
		}
		tailPtr = current;
	}
} // end LL to DLL 

void DoublyLinkedList::reverse()
{
	Node *ptr = headPtr;
	while (ptr != nullptr) {
		Node *tmp = ptr->getNext();
		ptr->setNext(ptr->getPrev());
		ptr->setPrev(tmp); 
		if (tmp == nullptr) {
			tailPtr = headPtr;
			headPtr = ptr;
		}
		ptr = tmp;
	}

} // end reverse
void DoublyLinkedList::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear

vector<ItemType> DoublyLinkedList::toVector(bool reverse)
{
	vector<ItemType> list; 
	Node* current = (reverse ? tailPtr : headPtr);
	while (current != nullptr) 
	{
		list.push_back(current->getItem());
		current = (reverse ? current->getPrev() : current->getNext());
	}
	return list; 
}

int DoublyLinkedList::getLength() const
{
	return itemCount;
}  // end getLength

bool DoublyLinkedList::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


ItemType DoublyLinkedList::getEntry(int position) const
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		
		Node* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
		
	}
	else
	{
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(message);
	}
}  // end getEntry


bool DoublyLinkedList::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

	if (ableToInsert)
	{
		// Create a new node containing the new entry
		Node* newNodePtr = new Node(newEntry);

		// Attach new node to chain
		if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			//Prev is already nullptr
			headPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new node
			newNodePtr->setPrev(getNodeAt(newPosition - 1));

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(newNodePtr->getPrev()->getNext());
			newNodePtr->getPrev()->setNext(newNodePtr);

			if (newPosition = getLength()) tailPtr = newNodePtr;
		}
		itemCount++; // Increase count of entries
	}

	return ableToInsert;
}  // end insert


bool DoublyLinkedList::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
			// Set previous to null
			if (headPtr != nullptr)
				headPtr->setPrev(nullptr);

		}
		else
		{
			// Find node that is before the one to remove
			Node* prevPtr = getNodeAt(position - 1);

			// Point to node to remove
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
			curPtr->getNext()->setPrev(prevPtr);
		}

		// Return node to system
		curPtr->setNext(nullptr);
		curPtr->setPrev(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--; // Decrease count of entries
	}

	return ableToRemove;
}  // end remove


ItemType DoublyLinkedList::replace(int position, const ItemType& newEntry)
{
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace)
	{
		Node* entryPtr = getNodeAt(position);
		ItemType oldEntry = entryPtr->getItem();
		entryPtr->setItem(newEntry);

		return oldEntry;
	}
	else
	{
		std::string message = "replace() called with an empty list or ";
		message = message + "invalid position.";
		throw(message);
	}
}  // end replace


Node* DoublyLinkedList::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Count from the beginning of the chain
	Node* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}  // end getNodeAt


DoublyLinkedList::~DoublyLinkedList()
{
	clear();
} // end destructor