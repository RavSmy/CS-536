#include <cstddef>
#include <iostream>
#include <vector>
#include "Employee.h"

using namespace std;

class BST {
    private:
        Employee *headptr;
        
    public:
        BST(); 
       // Employee find(int id);
        void insert (Employee *emp);
        void addHelper (Employee *root, Employee *add);

        //void Delete(int key);
        //void delHelper(Employee *parent, int key); 

        int size();
        int height();
        vector<Employee> inOrder();
        vector<Employee> vectorhelper (Employee *root); 

};
