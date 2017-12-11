#include "BST.h"
#include <string>


using namespace std;

BST::BST() : headptr(NULL){}

//Employee Employee::find(int id){}

void BST::insert (Employee *emp){ 

    if (headptr != NULL) {this->addHelper(headptr, emp);}
    else headptr = emp;

}

void BST::addHelper (Employee *root, Employee *add){  
    if ( root->getID() > add->getID() ) {
        if (root->getLeft() == NULL) root->setLeft(add);
        else addHelper (root->getLeft(), add);
    } 
    else {
        if (root->getRight() == NULL) root->setRight(add);
        else addHelper (root->getRight(), add);
     } 
}

vector<Employee> Employee::inOrder(){
}


void Employee::Delete(int key){  
    delHelper(headptr, key);
}

void Employee::delHelper(Employee *parent, int key) {
      if (key < this->key) {
            if (left != NULL)
                  left->remove(key, this);
            else
                  return NULL;
      } else if (key > this->key) {
            if (right != NULL)
                  return right->remove(key, this);
            else
                  return NULL;
      } else {
            if (left != NULL && right != NULL) {
                  this->key = right->minValue();
                  return right->remove(this->key, this);
            } else if (parent->left == this) {
                  parent->left = (left != NULL) ? left : right;
                  return this;
            } else if (parent->right == this) {
                  parent->right = (left != NULL) ? left : right;
                  return this;
            }
      }
}


