#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    BST *bst = new BST(); 

    bst->insert(new Employee(100, "Alice"));
    bst->insert(new Employee(50, "Betsy"));
    bst->insert(new Employee(500, "Cathy"));
    
  
} 
