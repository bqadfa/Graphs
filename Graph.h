#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


class Graph
{
	vector<vector <int>> arr;
	int n;
public:
	Graph();
	Graph(int n);

	int getN() { return n; }

	void setN(int n) { this->n = n; }
	void show()
	{
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cout << setw(4) << arr[i][j];
			cout << endl;
		}
	}
	~Graph();
};

