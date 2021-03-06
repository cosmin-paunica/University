#include "Polynomial.h"
#include <cmath>
#include <exception>
#include <iostream>

using namespace std;

// constructor ce creaza polinomul nul, avand gradul -1 
Polynomial::Polynomial() : degree(-1), coef(new double[1]) {
	coef[0] = 0;
}

// constructor ce creaza un polinom, fiind dat gradul si un vector de coeficienti
Polynomial::Polynomial(int degree, double* coef) : degree(degree) {
	if (degree < -1)
		throw invalid_argument("Invalid degree");
	if (degree == -1) {
		this->coef = new double[1];
		if (coef[0] != 0)
			throw invalid_argument("Non-zero coefficient for null polynomial");	// vrem ca polinomul nul (cu grad -1) sa aiba un unic coeficient nul
		this->coef[0] = 0;
	}
	else {
		this->coef = new double[degree + 1];
		for (int i = 0; i <= degree; i++) {
			if (i == degree && coef[i] == 0)
				throw invalid_argument("Dominant coefficient is null");	// ultimul coeficient trebuie sa fie nenul, altfel ar scadea gradul
			this->coef[i] = coef[i];
		}
	}
}

// constructor de copiere
Polynomial::Polynomial(const Polynomial& p) : degree(p.degree) {
	if (p.degree == -1) {
		this->coef = new double[1];
		this->coef[0] = 0;
	}
	else {
		this->coef = new double[p.degree + 1];
		for (int i = 0; i <= degree; i++)
			this->coef[i] = p.coef[i];
	}
}

// destructor
Polynomial::~Polynomial() {
	delete[] coef;		// nu verificam daca coef != NULL deoarece implementarea clasei nu permite un asemenea caz
}

// metoda ce calculeaza valoarea polinomului intr-un anumit punct
double Polynomial::computeValueAt(int x) const {
	double val = 0;
	for (int i = 0; i <= degree; i++)
		val += coef[i] * pow(x, i);
	return val;
}

// metoda ce adauga un termen de grad i
void Polynomial::addTerm(double c, int i) {
	if (i < 0)
		throw out_of_range("Negative index");
	if (i > degree && c != 0) {							// daca indicele este mai mare ca gradul si termenul de adaugat
														// este nenul, lungesc vectorul de coeficienti
		double* coef = new double[i + 1];
		for (int j = 0; j <= degree; j++)		// copiem toate valorile vechi ale coeficientilor
			coef[j] = this->coef[j];
		for (int j = degree + 1; j < i; j++)	// adaugam zerouri pana la termenul de grad i
			coef[j] = 0;
		delete[] this->coef;				// nu verificam daca this->coef != NULL deoarece implementarea clasei nu permite un asemenea caz
		this->coef = coef;
		degree = i;
	}
	else
		if (coef[i] != 0)
			throw invalid_argument("Term already exists");	// se cere adaugarea unui termen;
															// daca el deja exista, insemna ca l-am modifica, nu ca l-am adauga
	coef[i] = c;
}

// metoda ce elimina un termen de grad i
void Polynomial::removeTerm(int i) {
	if (i < 0 || i > degree)
		throw out_of_range("Invalid index");
	if (i == degree) {						// daca eliminam fix termenul dominant, scade gradul polinomului
		degree--;
		while (this->coef[degree] == 0)		// gradul scade cu 1 pentru fiecare coeficient nul ce precede coeficientul dominant
			degree--;
		if (degree == -1) {					// cazul in care polinomul devine nul
			double* coef = new double[1];
			coef[0] = 0;
			delete[] this->coef;			// nu verificam daca this->coef != NULL deoarece implementarea clasei nu permite un asemenea caz
			this->coef = coef;
		}
		else {								// cazul in care polinomul nu devine nul
			double* coef = new double[degree + 1];
			for (int j = 0; j <= degree; j++)
				coef[j] = this->coef[j];
			delete[] this->coef;
			this->coef = coef;
		}
	}
	else {									// daca eliminam alt termen in afara de cel dominant
		if (this->degree == 0)				// in cazul in care polinomul era de grad 0, el devine polinomul nul
			this->degree = -1;
		this->coef[i] = 0;
	}
}

// metoda ce returneaza gradul polinomului
int Polynomial::getDegree() const {
	return degree;
}

ostream& operator<<(ostream& out, const Polynomial& p) {
	if (p.degree == -1) {				// afisarea polinomului nul
		out << 0;
		return out;
	}
	bool unTermenAfisat = false;
	for (int i = 0; i <= p.degree; i++)
		if (p.coef[i] != 0) {			// nu afisam termenii cu coeficient 0
			if (unTermenAfisat)			// daca deja am afisat termeni ai polinomului, afisam in fata termenului curent " + "
				if (p.coef[i] > 0)
					out << " + ";
				else
					out << " - ";
			else						// daca suntem la primul termen, nu mai afisam " + " in fata sa
				unTermenAfisat = true;
			if (p.coef[i] == 1 || p.coef[i] == -1) {		// daca coeficientul este 1, nu il mai afisam nici pe el, nici simbolul "*"
				if (i >= 2)
					out << "X^" << i;
				else if (i == 1)		// daca suntem la termenul de grad 1, nu mai afisam "^1"
					out << "X";
				else					// daca suntem la termenul de grad 0, nu mai afisam "*X^i"
					out << p.coef[i];
			}
			else {						// in acest else, cazurile sunt similare cu cele de mai sus
				if (p.coef[i] > 0 || i == 0)
					out << p.coef[i];
				else
					out << -p.coef[i];
				if (i >= 2)
					out << "*X^" << i;
				else if (i == 1)
					out << "*X";
			}
		}
	return out;
}

istream& operator>>(istream& in, Polynomial& p) {
	delete[] p.coef;					// nu verificam daca p.coef != NULL, deoarece implementarea clasei nu permite un asemenea caz
	in >> p.degree;
	if (p.degree == -1) {				// daca am citit -1, polinomul este nul
		p.coef = new double[1];
		in >> p.coef[0];
		if (p.coef[0] != 0)
			throw logic_error("Non-zero coefficient for null polynomial");	// pentru ca polinomul sa fie nul, unicul sau coeficient trebuie sa fie 0
		return in;
	}
	p.coef = new double[p.degree + 1];
	for (int i = 0; i <= p.degree; i++) {
		in >> p.coef[i];
		if (i == p.degree && p.coef[i] == 0)
			throw invalid_argument("Dominant coefficient is null");			// termenul dominant nu trebuie sa fie 0
	}
	return in;
}

Polynomial Polynomial::operator=(const Polynomial& p) {
	if (&p == this)
		return *this;

	delete[] coef;				// nu verificam daca coef != NULL, deoarece implementarea clasei nu permite un asemenea caz
	degree = p.degree;
	if (p.degree == -1) {
		coef = new double[1];
		coef[0] = 0;
	}
	else {
		coef = new double[degree + 1];
		for (int i = 0; i <= degree; i++)
			coef[i] = p.coef[i];
	}
	return *this;
}

Polynomial operator+(const Polynomial& p, const Polynomial& q) {
	if (p.degree == -1)
		return q;
	if (q.degree == -1)
		return p;

	int degree;				// daca p.grad != q.grad, atunci grad = max(p.grad, q.grad)
	if (p.degree > q.degree)
		degree = p.degree;
	else if (p.degree < q.degree)
		degree = q.degree;
	else {					// altfel:
		degree = p.degree;
		while (degree >= 0 && p.coef[degree] + q.coef[degree] == 0)	// gradul scade cu 1 pentru fiecare termeni care se anuleaza
			degree--;
	}

	if (degree == -1)
		return Polynomial();

	Polynomial result(degree, new double[degree + 1]);
	for (int i = 0; i <= degree; i++)
		if (i > q.degree)
			result.coef[i] = p.coef[i];
		else if (i > p.degree)
			result.coef[i] = q.coef[i];
		else
			result.coef[i] = p.coef[i] + q.coef[i];
	return result;
}

double Polynomial::operator[](int i) const {
	if (i < 0 || i > degree)
		throw out_of_range("Invalid index");
	return coef[i];
}

Polynomial operator*(const Polynomial& p, const Polynomial& q) {
	if (p.degree == -1 || q.degree == -1)
		return Polynomial();					// inmultirea cu polinomul nul furnizeaza polinomul nul
	int degree = p.degree + q.degree;
	Polynomial result(degree, new double[degree + 1]);
	for (int i = 0; i <= degree; i++)
		result.coef[i] = 0;					// coeficientii ce nu se obtin din inmultiri directe ale coeficientilor lui p si q vor fi 0
	for (int i = 0; i <= p.degree; i++)
		for (int j = 0; j <= q.degree; j++)
			result.coef[i + j] += p.coef[i] * q.coef[j];
	return result;
}

Polynomial operator*(const int& c, const Polynomial& p) {
	if (c == 0)
		return Polynomial();
	Polynomial result(p.degree, new double[p.degree + 1]);
	for (int i = 0; i <= p.degree; i++)
		result.coef[i] = c * p.coef[i];
	return result;
}

Polynomial operator*(const Polynomial& p, const int& c) {
	return c * p;
}

// Algoritmul clasic pentru impartirea polinoamelor.
// pCopy este initial p, iar la finalul algoritmului el va stoca restul.
// Totusi, pCopy nu este tratat exact ca un polinom din clasa Polinom, deoarece
// vectorul de coeficienti nu se micsoreaza pe masura ce ii scade gradul.
Polynomial operator/(const Polynomial& p, const Polynomial& q) {
	if (p.degree < 0)
		throw domain_error("Division by null polynomial");
	if (p.degree == -1)
		return Polynomial();
	if (p.degree < q.degree)
		return Polynomial();

	Polynomial pCopy = p;
	int degree = p.degree - q.degree;
	Polynomial result(degree, new double[degree + 1]);
	double* coef = new double[degree + 1];
	for (int i = degree; i >= 0; i--) {
		result.coef[i] = pCopy[pCopy.degree] / q[q.degree];
		for (int j = q.degree; j >= 0; j--)
			pCopy.coef[i + j] -= result.coef[i] * q.coef[j];
		pCopy.degree--;
		while (pCopy.coef[pCopy.degree] == 0)
			pCopy.degree--;
	}
	return result;
}

bool Polynomial::operator==(const Polynomial& p) {
	if (degree != p.degree)
		return false;
	for (int i = 0; i <= degree; i++)
		if (coef[i] != p.coef[i])
			return false;
	return true;
}

bool Polynomial::operator!=(const Polynomial& p) {
	return !(*this == p);
}