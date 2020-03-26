#ifndef REGULARGRAMMAR_H
#define REGULARGRAMMAR_H

#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

class RegularGrammar {
	set<char> N;
	map<char, set<string>> P;

public:
	bool checkAcceptance(string);
	friend istream& operator>>(istream&, RegularGrammar&);
};

#endif