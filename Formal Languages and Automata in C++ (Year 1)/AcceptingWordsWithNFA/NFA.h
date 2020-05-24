#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class NFA {
	set<int> Q, F;
	set<char> Sigma;
	set<int> q0;
	map<pair<int, char>, set<int>> delta;

public:
	set<int> getInitialState();
	friend istream& operator >> (istream&, NFA&);
	set<int> deltaStar(set<int> s, string w);
	bool isFinalState(int q);
};

#endif