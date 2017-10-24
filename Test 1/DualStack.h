#ifndef DUAL_STACK
#define DUAL_STACK

class DualStack
{
	private:
		int *p;
		int top1, top2; 
		int size; 

	public: 
		DualStack(int size); 

		bool push1(int x); 
		bool push2(int x);  
		int peek1(); 
		int peek2();
		bool pop1();
		bool pop2();			
		bool isFull1();
		bool isFull2();
		bool isEmpty1();
		bool isEmpty2();

		~DualStack(); 

};

#endif