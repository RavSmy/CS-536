#include <cstddef>

class BTNode
{
	private:
    	char item;
    	BTNode* left;
    	BTNode* right;
    	
    public:
        BTNode(char theItem);
        BTNode(char theItem, BTNode* l, BTNode* r);
        
        void setItem(char theItem);
        char getItem();
        
        void setLeft(BTNode* l);
        BTNode* getLeft();
        
        void setRight(BTNode* r);
        BTNode* getRight();
        
        bool isLeaf();
        
        // Need a copy constructor
};