#include "DFA.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	DFA M;

	ifstream fin("DFA.txt");
	fin >> M;
	fin.close();

	int lastState = M.deltaStar(M.getInitialState(), "aabaa");

	if (M.isFinalState(lastState))
		cout << "Cuvant acceptat";
	else
		cout << "Cuvant respins";

	return 0;
}