#include <cstddef>
#include <iostream>

using namespace std;

class Employee {
    private:
        int id;
        string name;
        Employee* left;
        Employee* right;  

    public:
        Employee(int theid, string thename);
        Employee(int theid, string thename, Employee* right, Employee* left);

        int getID();
        string getName();

        void setRight(Employee* rright);
        void setLeft(Employee* lleft); 
        Employee* getRight();
        Employee* getLeft(); 
        
};

