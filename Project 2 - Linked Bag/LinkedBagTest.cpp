// CS 536, PROJECT 2 (LinkedBagTest.cpp), Ravela Smyth 

#include "LinkedBag.h"
#include <iostream>
#include <string>
#include <vector>

void printVector(vector<int>& v)
{
   for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
   {
      cout << *i << " " ;
   }   
   cout << endl;
}


int main()
{
    LinkedBag bag1, bag2, bag3, bag4;
    bag1.add(1); bag1.add(2); bag1.add(2); bag1.add(3); bag1.add(3); 
    bag1.add(3); bag1.add(4); bag1.add(4); bag1.add(4); bag1.add(4); 
    bag1.add(5); bag1.add(5); bag1.add(5); bag1.add(5); bag1.add(5); 

    bag2.add(6); bag2.add(6); bag2.add(7); bag2.add(7); bag2.add(7);

    bag3.add(2); bag3.add(3); bag3.add(4); bag3.add(4); bag3.add(5); 
    bag3.add(6); bag3.add(7); 

    bag4.add(2); bag4.add(3); bag4.add(4); bag4.add(4); bag4.add(4); 
    bag4.add(4); bag4.add(5); bag4.add(3); 

   
   
    vector<int> b1 = bag1.toVector();
    cout << "bag 1: "; printVector(b1); 
   
    LinkedBag b1ub2 = bag1.unnion(bag2);
    vector<int> b1b2 = b1ub2.toVector();
    cout << "\nbag 1 union bag 2: "; printVector(b1b2); 

    LinkedBag b1ib3 = bag1.intersection(bag3);
    vector<int> b1b3 = b1ib3.toVector();
    cout << "\nbag 1 intersection bag 3: "; printVector(b1b3); 

    LinkedBag b1ib4 = bag1.difference(bag4);
    vector<int> b1b4 = b1ib4.toVector();
    cout << "\nbag 1 difference bag 4: "; printVector(b1b4); 

} // end main
