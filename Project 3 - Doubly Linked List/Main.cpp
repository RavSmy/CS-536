#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	DoublyLinkedList list;

	list.insert(1,'a');
	list.insert(2, 'b');
	list.insert(3, 'c');
	list.insert(4, 'd');
	
	cout << "list: ";
	for (int i = 1; i <= list.getLength(); i++)
	{
		cout << i;
		cout << list.getEntry(i) << " ";
	}


	cout << endl;

	list.clear();
	cout << "length [0]: " << list.getLength() << endl;
	cout << "isEmpty [1]: " << list.isEmpty() << endl;

}
