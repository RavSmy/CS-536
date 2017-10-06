#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList slist; 
    slist.insert(1,"aa");
    slist.insert(2,"bb");
    slist.insert(3,"cc");
    slist.insert(4,"dd");

    DoublyLinkedList dlist(slist); 


}
