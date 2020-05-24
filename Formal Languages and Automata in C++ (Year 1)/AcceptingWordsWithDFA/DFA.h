#ifndef DFA_H
#define DFA_H

#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

class DFA {
	set<int> Q, F;
	set<char> Sigma;
	int q0;
	map<pair<int, char>, int> delta;

public:
	DFA();
	DFA(set<int> Q, set<char> Sigma, map<pair<int, char>, int> delta, int q0, set<int> F);

	set<int> getQ() const;
	set<int> getF() const;
	set<char> getSigma() const;
	int getInitialState() const;
	map<pair<int, char>, int> getDelta() const;

	friend istream& operator>>(istream&, DFA&);
	friend ostream& operator<<(ostream&, const DFA&);

	bool isFinalState(int);
	int deltaStar(int, string);
};

#endif