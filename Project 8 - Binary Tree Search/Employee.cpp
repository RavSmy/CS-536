#include "Employee.h"

using namespace std;

Employee::Employee(int theid, string thename) : id(theid), name(thename), left(NULL), right(NULL){}

Employee::Employee(int theid, string thename, Employee* right, Employee* left) : id(theid), name(thename), left(left), right(right){}

int Employee::getID(){return id;}

string Employee::getName(){return name;}

void Employee::setRight(Employee* rright){right = rright;}

void Employee::setLeft(Employee* lleft){left = lleft;}

Employee* Employee::getRight(){return right;}

Employee* Employee::getLeft(){return left;} 

