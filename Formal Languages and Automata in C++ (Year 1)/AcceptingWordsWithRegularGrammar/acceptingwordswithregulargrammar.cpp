#include "RegularGrammar.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fin("RegularGrammar.txt");

	RegularGrammar R;
	fin >> R;
	fin.close();

	if (R.checkAcceptance("aabbb"))	// write here the word that you want checked
		cout << "Accepted";
	else
		cout << "Rejected";

	return 0;
}