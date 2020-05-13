// Clasa Polinom contine un int, ce reprezinta gradul polinomului, si un double*,
// ce reprezinta coeficientii sai. Coeficientii sunt stocati de la termenul cu
// gradul cel mai mic la termenul cu gradul cel mai mare. Pentru polinomul nul,
// am ales ca gradul sa fie -1 (in matematica, el este minus infinit), iar
// vectorul de coeficienti este [0]. Pentru polinoame nenule, vectorul de
// coeficienti va avea dimensiunea cu 1 mai mare decat gradul.
// Aplicatia este facuta astfel incat niciodata coef sa nu fie NULL,
// asa ca nu mai verific niciodata acest lucru atunci cand ii eliberez memoria.

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial {
	int degree;
	double* coef;

public:
	Polynomial();
	Polynomial(int, double*);
	Polynomial(const Polynomial&);
	~Polynomial();

	double computeValueAt(int) const;
	void addTerm(double, int);
	void removeTerm(int);
	int getDegree() const;

	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
	Polynomial operator=(const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	double operator[](int) const;
	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const int&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const int&);
	friend Polynomial operator/(const Polynomial&, const Polynomial&);
	bool operator==(const Polynomial&);	// operator folosit pentru teste
	bool operator!=(const Polynomial&);	// operator folosit pentru teste
};

#endif