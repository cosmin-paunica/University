// This program checks wether a given word is accepted by a given regular grammar or not.

#include "regulargrammar.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fin("regulargrammar.txt");

	RegularGrammar R;
	fin >> R;

	if (R.checkAcceptance("aabbb"))	// write here the word that you want checked
		cout << "Accepted";
	else
		cout << "Rejected";

	return 0;
}