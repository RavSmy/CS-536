// CS 536, PROJECT 1, Ravela Smyth -- "polynomial.cpp"

#include "polynomial.h"
#include <cmath>

void Polynomial::addTerm(int coefficient, int exponent) {
	thepolynomial[numberOfTerms()].exponent = exponent; 
	thepolynomial[numberOfTerms()].coefficient = coefficient;
	num_of_terms++; 
}

/*ACCESSORS*/
int Polynomial::degree() {
	int degree = 0; 
	for (int i = 0; i < numberOfTerms(); i++)
		if (thepolynomial[i].exponent > degree) degree = thepolynomial[i].exponent; 
	return degree;
}

int Polynomial::coefficient(int power) {
	for (int i = 0; i < numberOfTerms(); i++)
		if (thepolynomial[i].exponent == power) return thepolynomial[i].coefficient; 
	return 0;
}

int Polynomial::value(int x) {
	int value = 0; 
	for (int i = 0; i < numberOfTerms(); i++)
		value += thepolynomial[i].coefficient * pow(x, thepolynomial[i].exponent);
	return value;
}

int Polynomial::numberOfTerms() {
	return num_of_terms; 
}

