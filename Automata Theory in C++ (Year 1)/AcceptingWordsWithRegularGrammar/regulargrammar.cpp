#include "regulargrammar.h"
#include <fstream>
#include <string>

using namespace std;

bool RegularGrammar::checkAcceptance(string s) {
	set<char> localNonTerminals;
	localNonTerminals.insert('S');

	while (s.length() > 0) {
		set<char> aux;
		for (char nonTerminal : localNonTerminals)
			for (string value : P[nonTerminal])
				if (value[0] == s[0] && value.length() == 1 && s.length() == 1)
					return true;
				else if (value[0] == s[0] && value.length() == 2)
					aux.insert(value[1]);

		if (aux.begin() == aux.end())
			return false;

		localNonTerminals.clear();
		for (char nonTerminal : aux)
			localNonTerminals.insert(nonTerminal);

		s = s.substr(1, s.length() - 1);
		aux.clear();
	}

	for (char nonTerminal : localNonTerminals)
		for (string value : P[nonTerminal])
			if (value == "#")
				return true;

	return false;
}

istream& operator>>(istream& fin, RegularGrammar& R) {
	int noOfNonterminals;
	fin >> noOfNonterminals;
	for (int i = 0; i < noOfNonterminals; i++) {
		char nonTerminal;
		fin >> nonTerminal;
		R.N.insert(nonTerminal);
	}

	for (int i = 0; i < noOfNonterminals; i++) {
		char nonTerminal;
		fin >> nonTerminal;
		int noOfLocalProductions;
		fin >> noOfLocalProductions;
		for (int i = 0; i < noOfLocalProductions; i++) {
			string s;
			fin >> s;
			R.P[nonTerminal].insert(s);
		}
	}

	return fin;
}