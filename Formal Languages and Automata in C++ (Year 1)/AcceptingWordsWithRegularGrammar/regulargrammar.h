#ifndef REGULARGRAMMAR_H
#define REGULARGRAMMAR_H

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class RegularGrammar {
	set<char> N;				// multimea neterminalelor
	map<char, set<string>> P;	// productiile

public:
	bool checkAcceptance(string);
	friend istream& operator>>(istream&, RegularGrammar&);
};

#endif