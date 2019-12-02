#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <queue>
#include <list>

using namespace std;


void arrShow(int **arr, int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << setw(3) << arr[i][j];
		cout << endl;
	}
}

void bfs(int u)
{
	vector<bool> v;
	vector<vector<int> > g;

	queue<int> q;

	q.push(u);
	v[u] = true;

	while (!q.empty()) {

		int f = q.front();
		q.pop();

		cout << f << " ";

		// Enqueue all adjacent of f and mark them visited  
		for (auto i = g[f].begin(); i != g[f].end(); i++) {
			if (!v[*i]) {
				q.push(*i);
				v[*i] = true;
			}
		}
	}
}



void main()
{
	int nSize;/*, mSize;*/
	
	cout << "Enter vertex number:\n"; cin >> nSize/* >> mSize*/;
	int **arr = new int *[nSize]; //Выделение памяти для матрицы смежности
	for (int i = 1; i <= nSize; i++)
		arr[i] = new int[nSize];

	int **arrIncid = new int *[nSize]; // Выделение памяти для матрицы инцидентности
	for (int i = 1; i <= nSize; i++)
		arrIncid[i] = new int[nSize];

	for (int i = 1; i <= nSize; i++)
		for (int j = 1; j <= nSize; j++)
			arr[i][j] = 0;

	for (int i = 1; i <= nSize; i++)
		for (int j = 1; j <= nSize; j++)
			arrIncid[i][j] = 0;

	//arrShow(arr, nSize);

	int u, v;

	list <pair<int, int>> lst; // Алгебраическое представление (ввод)
	auto it = lst.begin();
	for (int i = 1; i <= nSize; i++) {
		cout << "Enter connections (int int):\n"; cin >> u >> v;
		pair<int, int> p(u, v);
		lst.insert(it, p);
		
		/*for (int j = 1; j <= nSize; j++)
		{
			arr[u][v] == 1;
			arr[v][u] == 1;
		}*/

		for (int j = 1; j <= nSize; j++) {
			if (i == u && j == v) {
				arr[i][j] = 1;
				arr[j][i] = 1;
			}
		}
	}

	int x = 0;
	for (int i = 1; i <= nSize; i++)
	{
		for (int j = i; j <= nSize; j++)
		{
			if (arr[i][j] == 1)
			{
				arrIncid[i][x] = 1;
				arrIncid[j][x] = 1;
				x++;
			}
		}
	}

	cout << "\n-------------Adjacency matrix (Smejnosti):-------------\n";
	arrShow(arr, nSize);

	cout << "\n-------------Incidence matrix:-------------\n";
	arrShow(arrIncid, nSize);

	cout << "\n-------------Adjacency list:-------------\n";
	for (auto x : lst)
		cout << x.first << "->" << x.second << endl;

	


	cout << "Creaating high massive:\n";
	int* highMassive = new int[nSize];
	for (int y = 1; y <= nSize; y++)
	{
		cout << "Creating bool check Array. y = " << y << endl;
		bool* checkArray = new bool[nSize];

		for (int i = 1; i <= nSize; i++)
			checkArray[i] = false;
		cout << "Creating a queue.\n";
		queue <int> q;
		int check = 0;
		int dlina = 0;
		cout << "Pushing y into queue\n";
		/*q.push(y);
		q.push(y);*/
		cout << q.size() << " - queue size\n";
		checkArray[y] = true;
		while (!q.empty()) {
			for (int i = 1; i <= nSize; i++)
				if (arr[q.front()][i] == 1)
					if (checkArray[i] == false)
					{
						cout << "Check = " << check << endl;
						cout << q.size() << " - queue size\n";
						q.push(i);
						checkArray[i] = true;
						check++;
					}
			if (q.front() == y)
			{
				if (check < nSize - 1)
					q.push(y);
				dlina++;
			}
			cout << q.size() << " - queue size\n";
			cout << "Popping out element from queue.\n";
			q.pop();
		}
		highMassive[y] = dlina;
	}
	int diametr = highMassive[1];
	for (int i = 2; i <= nSize - 1; i++)
		if (diametr < highMassive[i])
			diametr = highMassive[i];
	for (int i = 1; i <= nSize; i++)
		if (diametr == highMassive[i])
			cout << "the most high vertex:" << i << endl;
	int radius = highMassive[1];
	for (int i = 2; i <= nSize - 1; i++)
		if (radius > highMassive[i])
			radius = highMassive[i];
	for (int i = 1; i <= nSize; i++)
		if (radius == highMassive[i])
			cout << "the lowest vertex:" << i << endl;


	cout << "\n-------------Diameter:-------------\n";
	cout << diametr << endl;

	cout << "\n-------------Radius:-------------\n";
	cout << radius << endl;



	_getch();
	system("pause>null");
}