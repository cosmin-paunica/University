#include "LambdaNFA.h"
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main() {
	LambdaNFA A;

	ifstream f("LambdaNFA.txt");
	f >> A;
	f.close();

	set<int> lastState = A.deltaStar("a");

	bool ok = false;
	for (int i : lastState)
		if (A.isFinalState(i))
			ok = true;

	if (ok)
		cout << "Cuvant acceptat";
	else
		cout << "Cuvant respins";

	return 0;
}