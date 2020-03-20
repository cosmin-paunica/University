// Clasa Polinom contine un int, ce reprezinta gradul polinomului, si un double*,
// ce reprezinta coeficientii sai. Coeficientii sunt stocati de la termenul cu
// gradul cel mai mic la termenul cu gradul cel mai mare. Pentru polinomul nul,
// am ales ca gradul sa fie -1 (in matematica, el este minus infinit), iar
// vectorul de coeficienti este [0]. Pentru polinoame nenule, vectorul de
// coeficienti va avea dimensiunea cu 1 mai mare decat gradul.
// Aplicatia este facuta astfel incat niciodata coef sa nu fie NULL,
// asa ca nu mai verific niciodata acest lucru atunci cand ii eliberez memoria.

#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>

using namespace std;

class Polinom {
	int degree;
	double* coef;

public:
	Polinom();
	Polinom(int, double*);
	Polinom(const Polinom&);
	~Polinom();

	double computeValueAt(int) const;
	void addTerm(double, int);
	void removeTerm(int);
	int getDegree() const;

	friend ostream& operator<<(ostream&, const Polinom&);
	friend istream& operator>>(istream&, Polinom&);
	Polinom operator=(const Polinom&);
	friend Polinom operator+(const Polinom&, const Polinom&);
	double operator[](int) const;
	friend Polinom operator*(const Polinom&, const Polinom&);
	friend Polinom operator*(const int&, const Polinom&);
	friend Polinom operator*(const Polinom&, const int&);
	friend Polinom operator/(const Polinom&, const Polinom&);
};

#endif