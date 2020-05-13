#include "Polynomial.h"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

void tests();

int main() {
	tests();

	return 0;
}

void tests() {
	double coefP1[5] = { -2, 3, 0, -5, 2 };
	Polynomial p1(4, coefP1);
	double coefP2[3] = { 4, -2, 1 };
	Polynomial p2(2, coefP2);

	// testare constructor de copiere
	Polynomial p3 = p1;
	assert(p1 == p3);
	p3.addTerm(4, 6);
	assert(p1 != p3);

	// testare operator de atribuire (=)
	Polynomial p4;
	p4 = p1;
	assert(p1 == p4);
	p4.addTerm(4, 6);
	assert(p1 != p4);

	// testare metoda pentru calcularea valorii intr-un punct
	assert(p1.computeValueAt(2) == -4);

	// testare metode pentru adaugarea si eliminarea unui termen
	double coefP1Extended[5] = { -2, 3, 4, -5, 2 };
	Polynomial p1Extended(4, coefP1Extended);
	Polynomial p1Old = p1;

	p1.addTerm(4, 2);
	assert(p1 == p1Extended);
	p1.removeTerm(2);
	assert(p1 == p1Old);

	// testare metoda ce returneaza gradul polinomului
	assert(p1.getDegree() == 4);

	// testare operatori aritmetici
	double coefSum[5] = { 2, 1, 1, -5, 2 };
	Polynomial sum(4, coefSum);
	assert(p1 + p2 == sum);

	double coefProduct[7] = { -8, 16, -8, -17, 18, -9, 2 };
	Polynomial product(6, coefProduct);
	assert(p1 * p2 == product);

	double coefScaledPolynomial[5] = { -4, 6, 0, -10, 4 };
	Polynomial scaledPolynomial(4, coefScaledPolynomial);
	assert(2 * p1 == scaledPolynomial);

	double coefQuotient[3] = { -10, -1, 2 };
	Polynomial quotient(2, coefQuotient);
	assert(p1 / p2 == quotient);

	// testare operator []
	assert(p1[3] == -5);

	// testare operatori >> si <<
	ifstream fin("in.txt");
	Polynomial p5;
	fin >> p5;
	cout << p5 << endl << endl;

	cout << "The tests have passed." << endl;
}