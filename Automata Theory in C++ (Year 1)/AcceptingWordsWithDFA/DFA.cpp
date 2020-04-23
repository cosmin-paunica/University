#include "DFA.h"

DFA::DFA() {
	this->q0 = 0;
}

DFA::DFA(set<int> Q, set<char> Sigma, map<pair<int, char>, int> delta, int q0, set<int> F) {
	this->Q = Q;
	this->Sigma = Sigma;
	this->delta = delta;
	this->q0 = q0;
	this->F = F;
}

set<int> DFA::getQ() const {
	return Q;
}

set<int> DFA::getF() const {
	return F;
}

set<char> DFA::getSigma() const {
	return Sigma;
}

int DFA::getInitialState() const {
	return q0;
}

map<pair<int, char>, int> DFA::getDelta() const {
	return delta;
}

bool DFA::isFinalState(int q) {
	return F.find(q) != F.end();
}

int DFA::deltaStar(int q, string w) {
	if (w.length() == 0)
		return q;
	if (w.length() == 1) {
		return delta[{q, (char)w[0]}];
	}

	int new_q = delta[{q, (char)w[0]}];
	return deltaStar(new_q, w.substr(1, w.length() - 1));
}

istream& operator>>(istream& in, DFA& M) {
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
		int s, d;
		char ch;
		in >> s >> ch >> d;
		M.delta[{s, ch}] = d;
	}

	in >> M.q0;

	int noOfFinalStates;
	in >> noOfFinalStates;
	for (int i = 0; i < noOfFinalStates; ++i) {
		int q;
		in >> q;
		M.F.insert(q);
	}

	return in;
}

ostream& operator<<(ostream& out, const DFA& M) {
	for (int q : M.Q)
		out << q << " ";
	out << endl;

	for (char ch : M.Sigma)
		out << ch << " ";
	out << endl;

	for (auto transition : M.delta) {
		out << transition.first.first << " " << transition.first.second << " " << transition.second << endl;
	}

	out << M.q0 << endl;

	for (int q : M.F)
		out << q << " ";

	return out;
}