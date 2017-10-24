#include<iostream>
#include "DualStack.h"
using namespace std;

DualStack::DualStack(int msize) 
{
	top1 = -1, top2 = msize; 
	p = new int[msize];
	size = msize; 
}

bool DualStack::push1(int x) {
	if (isFull1()) return false; 
	*(p+(++top1)) = x; 
	return true;
};

bool DualStack::push2(int x) {
	if (isFull2()) return false;
	*(p+(--top2)) = x;
	return true;
};

int DualStack::peek1() {
	if (isEmpty1()) throw( "Cannot peek, stack is empty! ");
	return *(p+(top1));
};

int DualStack::peek2() {
	if (isEmpty2()) throw("Cannot peek, stack is empty! ");
	return *(p+(top2));
};

bool DualStack::pop1() {
	if (isEmpty1()) return false;
	--top1; 
	return true;
};
bool DualStack::pop2() {
	if (isEmpty2()) return false;
	++top2;
	return true;
};

bool DualStack::isFull1() {
	return top1+1 == top2; 
};

bool DualStack::isFull2() {
	return top2-1 == top1;
};

bool DualStack::isEmpty1() {
	return top1 == -1;
};

bool DualStack::isEmpty2() {
	return top2 == size;
};

DualStack::~DualStack() {
	delete p; 
	p = nullptr; 
}