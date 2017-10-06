#include "DoublyLinkedList.h"
#include <cassert>
using namespace std; 

DoublyLinkedList::DoublyLinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
}  // end default constructor

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &obj)
{
    if(obj.head == NULL) head = NULL;
    else 
    {
        headPtr = new Node(obj.headPtr->getItem());
        Node *current = headPtr;
        Node *currentObj = obj.headPtr;
        while (currentObj->getNext() != NULL) 
        {
            current->setNext(currentObj->getNext());
            current->setPrev(currentObj->getPrev());
            current = current->getNext(); 
            currentObj = currentObj->getNext();
        } 
    } 

}//end deep copy constructor

DoublyLinkedList::DoublyLinkedList(const LinkedList &obj) 
{
    if(obj.head == NULL) head = NULL;
    else 
    {
        headPtr = new Node(obj.headPtr->getItem());
        Node *current = headPtr;
        Node *currentObj = obj.headPtr;
        while (currentObj->getNext() != NULL) 
        {
            current->setNext(new Node(currentObj->getNext()->getItem()));
            current->getNext()->setPrev(current);
            current = current->getNext(); 
            currentObj = currentObj->getNext();
        }  
    }  
} // end LL to DLL

void DoublyLinkedList::reverse()
{
    Node* temp = headPtr; 
    Node* current = headPtr; 
    headPtr = tailPtr;
    tailPtr = temp;
    
    do while(current->getNext() != NULL)
    {
        temp = current->getNext();
        current->setNext(current->getPrev());
        current->setPrev(temp);
        current = current->getPrev(); 
    }

} // end reverse
void DoublyLinkedList::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear


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
