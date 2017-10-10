// CS 536, PROJECT 3, Ravela Smyth -- "Main.cpp"

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList slist;
	slist.insert(1, "aa");
	slist.insert(2, "bb");
	slist.insert(3, "cc");
	slist.insert(4, "dd");
	

	DoublyLinkedList dlist(slist);

	cout << "Step 3 dlist: \t";
	vector<ItemType> list1 = dlist.toVector(false);
	for (int i = 0; i < dlist.getLength(); i++) cout << "   " << list1[i]  ;

	cout << "\nStep 4 dlist: \t";
	vector<ItemType> list2 = dlist.toVector(true);
	for (int i = 0; i < dlist.getLength(); i++) cout << "   " << list2[i];


	dlist.reverse();

	cout << "\nStep 6 dlist: \t";
	vector<ItemType> list3 = dlist.toVector(false);
	for (int i = 0; i < dlist.getLength(); i++) cout << "   " << list3[i];


	DoublyLinkedList dlist2(dlist);

	cout << "\nStep 8 dlist2: \t";
	vector<ItemType> list5 = dlist2.toVector(false);
	for (int i = 0; i < dlist2.getLength(); i++) cout << "   " << list5[i];


	dlist2.reverse();

	cout << "\nStep 10 dlist2: ";
	vector<ItemType> list6 = dlist2.toVector(false);
	for (int i = 0; i < dlist2.getLength(); i++) cout << "   " << list6[i];


	cout << "\nStep 11 dlist:  ";
	vector<ItemType> list7 = dlist.toVector(false);
	for (int i = 0; i < dlist.getLength(); i++) cout << "   " << list7[i];
	
	cout << '\n';

	dlist.clear(); dlist2.clear(); slist.clear();
}