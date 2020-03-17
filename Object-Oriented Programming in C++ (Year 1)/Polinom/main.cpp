// cateva teste pentru functionalitatile oferite de clasa Polinom

#include "polinom.h"
#include <iostream>

using namespace std;

int main() {
	double coef[3] = { 1, 2, 1 };
	Polinom p(2, coef);
	cout << "p  =  " << p << endl;

	Polinom q = p;
	q.addTerm(1, 5);
	cout << "q  =  " << q << endl;

	Polinom f;
	f = p + q;
	cout << "f  =  " << f << " ( =  f + g)" << endl;
	cout << endl;

	cout << "Valoarea polinomului f in punctul 1 este: " << f.computeValueAt(1) << endl;
	cout << "Termenul de grad 1 al polinomului f este: " << f[1] << endl;
	cout << endl;

	cout << "2 * f  =  " << 2 * f << endl;
	cout << "f * 3  =  " << f * 3 << endl;
	cout << "p + f  =  " << p + f << endl;
	cout << "p * f  =  " << p * f << endl;
	cout << endl;

	double coef1[5] = { -2, 3, 0, -5, 2 };
	double coef2[3] = { 4, -2, 1 };
	cout << "Impartirea polinoamelor este: " << Polinom(4, coef1) / Polinom(2, coef2) << endl;
	cout << endl;

	Polinom g;
	cout << "Introdceti un polinom de grad cel putin 2:" << endl;
	cin >> g;
	cout << "g  =  " << g << endl;
	g.removeTerm(g.getDegree());
	cout << "g  =  " << g << endl;
	g.removeTerm(1);
	cout << "g  =  " << g << endl;

	return 0;
}