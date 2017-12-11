// CS 536, PROJECT 2 (LinkedBag.cpp), Ravela Smyth 

#include "LinkedBag.h"
#include <algorithm>  

LinkedBag::LinkedBag() : headPtr(NULL), itemCount(0)
{
}  // end default constructor

LinkedBag LinkedBag::unnion(const LinkedBag& otherBag){
    LinkedBag* bag = new LinkedBag();
    vector<ItemType> o = otherBag.toVector();
    vector<ItemType> t = this->toVector();

    for (int i = 0 ; i < o.size() || i < t.size(); i++)
        { 
            if (i < o.size()) bag->add(o.at(i)); 
            if (i < t.size()) bag->add(t.at(i)); 
        }  

    return *bag;
}

LinkedBag LinkedBag::intersection(const LinkedBag& otherBag){
    LinkedBag* bag = new LinkedBag();

    vector<ItemType> o = otherBag.toVector();
    vector<ItemType> t = this->toVector();
    sort (o.begin(), o.end()); 
    sort (t.begin(), t.end());


    for (int i = 0, k =0 ; i < o.size() && k < t.size();) {
        if (t.at(k) == o.at(i)){ bag->add(o.at(i)); i++; k++;}
        else if (t.at(k) > o.at(i)) {i++;} 
        else k++;    
       }      

    return *bag;
}


LinkedBag LinkedBag::difference(const LinkedBag& otherBag){
    LinkedBag* bag = new LinkedBag();

    vector<ItemType> o = otherBag.toVector();
    vector<ItemType> t = this->toVector();
    sort (o.begin(), o.end()); 
    sort (t.begin(), t.end());


    for (int i = 0, k =0 ; i < o.size() || k < t.size();) {
        if (i >= o.size() || o.at(i) > t.at(k)){bag->add(t.at(k)); k++;} 
        else if (k >= t.size() || t.at(k) > o.at(i)) {bag->add(o.at(i)); i++;} 
        else {i++; k++;} 
       }      

    return *bag;
}


bool LinkedBag::add(const ItemType& newEntry)
{
   // (headPtr is null if chain is empty)        
   Node* nextNodePtr = new Node();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain

// alternate code: Node* nextNodePtr = new Node(newEntry, headPtr); 
   
   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;                    // The method is always successful
}  // end add


int LinkedBag::getCurrentSize() const
{
   return itemCount;
}  // end getCurrentSize


bool LinkedBag::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty


int LinkedBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int counter = 0;
   Node* curPtr = headPtr;
   while ((curPtr != NULL) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
   return frequency;
}  // end getFrequencyOf


// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
Node* LinkedBag::getPointerTo(const ItemType& target) const
{
   bool found = false;
   Node* curPtr = headPtr;
   
   while (!found && (curPtr != NULL))
   {
      if (target == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

bool LinkedBag::contains(const ItemType& anEntry) const
{
   return (getPointerTo(anEntry) != NULL);
}  // end contains


void LinkedBag::clear()
{
   Node* nodeToDeletePtr = headPtr;
   while (headPtr != NULL)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      delete nodeToDeletePtr;
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is NULL; nodeToDeletePtr is NULL
   
   itemCount = 0;
}  // end clear


bool LinkedBag::remove(const ItemType& anEntry)
{
   Node* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != NULL);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      delete nodeToDeletePtr;
      nodeToDeletePtr = NULL;
      
      itemCount--;
   } // end if
   
   return canRemoveItem;
}  // end remove


vector<ItemType> LinkedBag::toVector() const
{
   std::vector<ItemType> bagContents;
   Node* curPtr = headPtr;
   int counter = 0;
   while ((curPtr != NULL) && (counter < itemCount))
   {
      bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;

}  // end toVector


LinkedBag::~LinkedBag()
{
   clear();
}  // end destructor
