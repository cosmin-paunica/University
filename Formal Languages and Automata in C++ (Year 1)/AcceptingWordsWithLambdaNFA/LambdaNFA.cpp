#include "LambdaNFA.h"

set<int> LambdaNFA::getInitialState() {
	return this->q0;
}

set<int> LambdaNFA::lambdaClosure(int q) {
	set<int> closure;
	closure.insert(q);

	bool ok = true;
	set<int> aux, aux2;
	aux.insert(q);

	int v[1000];
	for (int i = 0; i < 99; i++)
		v[i] = 0;

	while (ok) {
		ok = false;
		for (int i : aux)
			for (int j : delta[{i, '#'}])
				if (v[j] == 0) {
					ok = true;
					v[j] = 1;
					closure.insert(j);
					aux2.insert(j);
				}
		aux.clear();
		for (int i : aux2)
			aux.insert(i);
		aux2.clear();
	}

	return closure;
}

set<int> LambdaNFA::deltaStar(string w) {
	int n = w.length();

	set<int> localFinalStates;
	//localFinalStates.insert(*(q0.begin()));
	for (int i : lambdaClosure(*(q0.begin())))
		localFinalStates.insert(i);

	int poz = 0;

	while (n) {
		set<int> closure;	// pentru "prima" lambda-inchidere din formula matematica (cea din interior)
		for (int i : localFinalStates)
			for (int j : lambdaClosure(i))
				closure.insert(j);

		set<int> aux;
		for (int i : closure)
			for (int j : delta[{i, w[poz]}])
				aux.insert(j);
		n--;
		poz++;

		// procedez similar ca la NFA: calculez in localFinalStates tranzitiile cu starile din closure cu prima litera din cuvant
		localFinalStates.clear();
		for (int i : aux)
			localFinalStates.insert(i);
		aux.clear();

		set<int> closure2;	// pentru "a doua" lambda-inchidere din formula matematica
		for (int i : localFinalStates)
			for (int j : lambdaClosure(i))
				closure2.insert(j);

		localFinalStates.clear();
		for (int i : closure2)
			localFinalStates.insert(i);
	}

	return localFinalStates;
}

bool LambdaNFA::isFinalState(int q) {
	return F.find(q) != F.end();
}

istream& operator >> (istream& in, LambdaNFA& M) {
	int noOfStates;
	in >> noOfStates;
	for (int i = 0; i < noOfStates; ++i) {
		int q;
		in >> q;
		M.Q.insert(q);
	}

	int noOfLetters;
	in >> noOfLetters;
	//M.Sigma.insert('#');
	for (int i = 0; i < noOfLetters; i++) {
		char ch;
		in >> ch;
		M.Sigma.insert(ch);
	}

	int noOfTransitions;
	in >> noOfTransitions;
	for (int i = 0; i < noOfTransitions; i++) {
		int s, nr, d;
		char ch;
		in >> s >> ch >> nr;
		set<int> x;
		for (int j = 0; j < nr; j++) {
			in >> d;
			x.insert(d);
		}
		M.delta[{s, ch}] = x;
	}

	int q_init;
	in >> q_init;
	M.q0.insert(q_init);

	int noOfFinalStates;
	in >> noOfFinalStates;
	for (int i = 0; i < noOfFinalStates; i++) {
		int q;
		in >> q;
		M.F.insert(q);
	}

	return in;
}