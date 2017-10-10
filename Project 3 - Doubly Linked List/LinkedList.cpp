#include "LinkedList.h"
#include <cassert>

LinkedList::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor


void LinkedList::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear


int LinkedList::getLength() const
{
	return itemCount;
}  // end getLength

bool LinkedList::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


ItemType LinkedList::getEntry(int position) const
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


bool LinkedList::insert(int newPosition, const ItemType& newEntry)
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
			headPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new node
			Node* prevPtr = getNodeAt(newPosition - 1);

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}

		itemCount++; // Increase count of entries
	}

	return ableToInsert;
}  // end insert


bool LinkedList::remove(int position)
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
		}

		// Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--; // Decrease count of entries
	}

	return ableToRemove;
}  // end remove

Node* LinkedList::getHeadPtr() const {
	return headPtr; 
}

ItemType LinkedList::replace(int position, const ItemType& newEntry)
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


Node* LinkedList::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Count from the beginning of the chain
	Node* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}  // end getNodeAt


LinkedList::~LinkedList()
{
	clear();
} // end destructor