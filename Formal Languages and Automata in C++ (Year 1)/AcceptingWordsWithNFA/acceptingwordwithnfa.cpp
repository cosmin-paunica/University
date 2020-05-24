#include "NFA.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	NFA A;

	ifstream f("NFA.txt");
	f >> A;
	f.close();

	set<int> lastStates = A.deltaStar(A.getInitialState(), "aa");

	bool ok = false;
	for (int i : lastStates)
		if (A.isFinalState(i))
			ok = true;

	if (ok)
		cout << "Cuvant acceptat";
	else
		cout << "Cuvant respins";

	return 0;
}