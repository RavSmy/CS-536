#include<iostream>
#include"DualStack.h"
using namespace std;

int main()
{
	DualStack hello(10);

	cout << "STEP 2 : Stack 1 empty? " << hello.isEmpty1() << "   Stack 2 empty? " << hello.isEmpty2(); 

	hello.push1(10); hello.push1(20); hello.push1(30); hello.push1(40);
	hello.push2(100); hello.push2(200); hello.push2(300); hello.push2(400); hello.push2(500); hello.push2(600);

	cout << "\nSTEP 5 : Stack 1 full? " << hello.isFull1() << "   Stack 2 full? " << hello.isFull2();
	cout << "\nSTEP 6 : Top of    Stack 1: " << hello.peek1() << "   Stack 2: " << hello.peek2();
	
	hello.pop1(); hello.pop1();
	hello.pop2(); hello.pop2(); hello.pop2();
	
	cout << "\nSTEP 9 : Top of    Stack 1: " << hello.peek1() << "   Stack 2: " << hello.peek2();

	hello.pop1(); hello.pop1();

	cout << "\nSTEP 11 : Stack 1 empty? " << hello.isEmpty1() << "   Stack 2 empty? " << hello.isEmpty2();
	cout << '\n';
}