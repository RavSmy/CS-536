// CS 536, PROJECT 1, Ravela Smyth -- "Main.cpp"

#include <iostream>
#include <fstream>
#include "polynomial.h"
using namespace std;

int main() {
	Polynomial mypolynomial; 
	int coeff, exp; 

	/*FILE INPUT*/
	ifstream file; 
	file.open("file2.txt");

	while (file >> coeff >> exp) {
		mypolynomial.addTerm(coeff, exp);
	}
	file.close();

	/*POLYNOMIAL MANIPULATION*/
	cout << "Degree: \t" << mypolynomial.degree() << "\n"; 
	cout << "# terms: \t" << mypolynomial.numberOfTerms() << "\n";
	
	for (int i = 0 ; i < mypolynomial.degree(); i++)
		cout << "coeff(" << i << "): \t" << mypolynomial.coefficient(i) << "\n";
	
	cout << "value(1): \t" << mypolynomial.value(1) << "\n";
	cout << "value(2): \t" << mypolynomial.value(2) << "\n";

	 
}