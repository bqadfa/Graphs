#include "Graph.h"



Graph::Graph()
{
	n = 5;
	int **arr = new int *[n];
	for (int i = 1; i <= n; i++)
		arr[i] = new int[n];
}

Graph::Graph(int n)
{
	this->n = n;
	int **arr = new int *[n];
	for (int i = 1; i <= n; i++)
		arr[i] = new int[n];
}


Graph::~Graph()
{
	//delete[]arr;
}
