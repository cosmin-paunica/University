#include "../AcceptingWordsWithDFA/DFA.h"
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// verifica daca un set de int-uri contine pe q
bool contains(int q, set<int> s) {
	for (int n : s)
		if (q == n)
			return true;
	return false;
}

// verifica daca doua stari ale unui DFA sunt separabile intr-o anumita configuratie de partitii
bool areSeparable(int q1, int q2, vector<set<int>> partitions, DFA M) {
	for (char ch : M.getSigma()) {
		int d1 = M.getDelta()[{q1, ch}], d2 = M.getDelta()[{q2, ch}];
		for (set<int> partition : partitions)
			if (contains(d1, partition) && !contains(d2, partition) || !contains(d1, partition) && contains(d2, partition))
				return true;
	}
	return false;
}

DFA minimize(DFA M) {
	vector<set<int>> partitions;

	set<int> A0, B0;	// A0 = Q\F, B0 = F
	for (int q : M.getQ())
		if (M.isFinalState(q))
			B0.insert(q);
		else
			A0.insert(q);
	partitions.push_back(A0);
	partitions.push_back(B0);

	bool done = false;
	while (!done) {	// mergem prin while cat timp gasim stari separabile
		done = true;

		vector<set<int>> newPartitions;

		for (unsigned i = 0; i < partitions.size(); i++) {
			for (auto q = partitions[i].begin(); q != partitions[i].end(); q++)
				if (areSeparable(*partitions[i].begin(), *q, partitions, M)) {
					done = false;

					bool partitionAlreadyExists = false;
					set<int> existentPartition;
					for (set<int> partition : newPartitions)
						if (!areSeparable(*partition.begin(), *q, newPartitions, M)) {
							partitionAlreadyExists = true;
							existentPartition = partition;
						}

					if (partitionAlreadyExists)
						existentPartition.insert(*q);
					else {
						set<int> newPartition;
						newPartition.insert(*q);
						newPartitions.push_back(newPartition);
					}

					q--;
					set<int>::iterator aux = q;
					q++;
					partitions[i].erase(q);
					q = aux;
				}
		}

		for (set<int> newPartition : newPartitions)
			partitions.push_back(newPartition);
	}

	set<int> Q, F;
	int q0 = 0;
	map<pair<int, char>, int> delta;

	int newState = 0;
	for (set<int> partition : partitions) {
		for (int q : partition) {
			if (q == M.getInitialState())
				q0 = q;
			if (M.isFinalState(q))
				F.insert(q);
		}
		Q.insert(newState++);	// introducem starile q0, q1, ... (si nu q01, q234, de exemplu)
	}

	for (unsigned i = 0; i < partitions.size(); i++) {
		for (char ch : M.getSigma()) {
			for (unsigned j = 0; j < partitions.size(); j++)
				if (contains(M.getDelta()[{*partitions[i].begin(), ch}], partitions[j]))
					delta[{i, ch}] = j;
		}
	}

	return DFA(Q, M.getSigma(), delta, q0, F);
}

int main() {
	ifstream fin("dfatobeminimized.txt");

	DFA M;
	fin >> M;
	fin.close();

	DFA A = minimize(M);
	cout << A << endl;

	return 0;
}