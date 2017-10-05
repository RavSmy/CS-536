#ifndef NODE_
#define NODE_

#include <string>
using namespace std;

typedef int ItemType;

class Node
{
private:
   ItemType  item;  // A data item
   Node*     next;  // Pointer to next node
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node* nextNodePtr);
   ItemType getItem() const ;
   Node* getNext() const ;
}; // end Node

#endif