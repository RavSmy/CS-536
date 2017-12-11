// CS 536, PROJECT 1, Ravela Smyth -- "polynomial.h"

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct terms {
	int coefficient, exponent; 
};

class Polynomial {
	private:
		struct terms thepolynomial[10]; 
		double num_of_terms = 0; 
	public:
		void addTerm(int coefficient, int exponent);

		// Accessors 
		int degree();
		int coefficient(int power);
		int numberOfTerms();
		int value(int x);
};

#endif