#include "NFA.h"

set<int> NFA::getInitialState() {
	return this->q0;
}

set<int> NFA::deltaStar(set<int> s, string w) {
	int n = w.length();
	set<int> localFinalStates;

	if (n == 0)
		return localFinalStates;

	// calculez tranzitiile cu prima litera a cuvantului din starea initiala
	for (int i : delta[{*(q0.begin()), w[0]}])
		localFinalStates.insert(i);
	n--;

	if (n == 0)
		return localFinalStates;

	int poz = 1;
	set<int> aux;

	// pentru fiecare litera a cuvantului (de la stanga la dreapta), calculez in aux tranzitiile cu aceasta si fiecare stare din localFinalStates
	while (n) {
		for (int i : localFinalStates)
			for (int j : delta[{i, w[poz]}])
				aux.insert(j);
		n--;
		poz++;

		// actualizez localFinalStates
		localFinalStates.clear();
		for (int i : aux)
			localFinalStates.insert(i);
		aux.clear();
	}

	return localFinalStates;
}

bool NFA::isFinalState(int q) {
	return F.find(q) != F.end();
}

istream& operator>>(istream& in, NFA& M) {
	int noOfStates;
	in >> noOfStates;
	for (int i = 0; i < noOfStates; ++i) {
		int q;
		in >> q;
		M.Q.insert(q);
	}

	int noOfLetters;
	in >> noOfLetters;
	for (int i = 0; i < noOfLetters; ++i) {
		char ch;
		in >> ch;
		M.Sigma.insert(ch);
	}

	int noOfTransitions;
	in >> noOfTransitions;
	for (int i = 0; i < noOfTransitions; ++i) {
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
	for (int i = 0; i < noOfFinalStates; ++i) {
		int q;
		in >> q;
		M.F.insert(q);
	}

	return in;
}