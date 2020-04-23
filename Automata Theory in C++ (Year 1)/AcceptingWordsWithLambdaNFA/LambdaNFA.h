#ifndef LAMBDANFA_H
#define LAMBDANFA_H

#include <istream>
#include <map>
#include <string>
#include <set>

using namespace std;

class LambdaNFA {
	set<int> Q, F;
	set<char> Sigma;
	set<int> q0;
	map<pair<int, char>, set<int>> delta;

public:
	set<int> getInitialState();
	friend istream& operator >> (istream&, LambdaNFA&);
	set<int> lambdaClosure(int q);
	set<int> deltaStar(string w);
	bool isFinalState(int q);
};

#endif