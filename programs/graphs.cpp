#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int n;
vector<vector<int>> g;


void GraphRead()
{
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	int m; cin >> m;
	g.resize(n);
	for (int i = 0; i < m; i++)
	{
		cout << "m[" << i + 1 << "] = ";
		int u, v; cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	cout << endl;
}


void task1()
{
	GraphRead();
	cout << "v = ";
	int v; cin >> v; v--;
	cout << "result = " << g[v].size() << endl;
}

void task2()
{
	GraphRead();
	int a, b;
	cout << "a = "; cin >> a; cout << "b = "; cin >> b;
	a--; b--;
	g[a].push_back(b);
	g[b].push_back(a);
	cout << endl;
	cout << "graph" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": ";
		for (int j = 0; j < g[i].size(); j++) cout << g[i][j] + 1 << ' ';
		cout << endl;
	}
}

void task3()
{
	GraphRead();
	cout << "result" << endl;
	for (int i = 0; i < n; i++) cout << i + 1 << ": " << g[i].size() << endl;
}



void dfs(int v, vector<int>& used)
{
	used[v] = 1;
	for (auto u : g[v]) if (!used[u]) dfs(u, used);
}

void task4()
{
	GraphRead();
	vector<int> used(n, 0);
	dfs(0, used);
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}




void bfs(int a, vector<int>& used)
{
	used[a] = 0;
	queue<int> q;
	q.push(a);
	while (q.size())
	{
		int v = q.front();
		q.pop();
		for (auto u : g[v])
		{
			if (used[u] == -1)
			{
				used[u] = used[v] + 1;
				q.push(u);
			}
		}
	}
}

void task5()
{
	GraphRead();
	int a, b;
	cout << "a = "; cin >> a; a--;
	cout << "b = "; cin >> b; b--;

	vector<int> used(n, -1);
	bfs(a, used);

	cout << "result = " << used[b] << endl;
}

int main()
{
	cout << "task = ";
	int task; cin >> task;
	switch (task)
	{
	case 1: 
	{
		task1();
		break;
	}
	case 2:
	{
		task2();
		break;
	}
	case 3:
	{
		task3();
		break;
	}
	case 4:
	{
		task4();
		break;
	}
	case 5:
	{
		task5();
		break;
	}
	default:
		break;
	}
}
