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
vector<vector<pair<int, int>>> g;
vector<vector<int>> ans;
vector<int> used, d;

const int INF = 1e8;

int main() {

	cout << "n = ";
	int n; cin >> n;
	g.resize(n); used.assign(n, 0); ans.resize(n); d.assign(n, INF);
	cout << "m = ";
	int m; cin >> m;
	for (int i = 0; i < m; i++)									//считывание графа
	{
		cout << "m[" << i + 1 << "] (u->v w) = ";
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		g[u].push_back({ v, w });
		g[v].push_back({ u,w });
	}

	cout << "x = ";												//искомая вершина
	int x; cin >> x; x--;
	d[x] = 0;
	queue <int> q;
	q.push(x);
	while (q.size())											//Дейкстра
	{
		int v = q.front();
		q.pop();
		for (auto p : g[v])
		{
			int u = p.first, w = p.second;
			if (d[u] > d[v] + w)
			{
				ans[u] = ans[v];
				ans[u].push_back(v);
				d[u] = d[v] + w;
				q.push(u);
			}
			else continue;
		}
	}

	cout << endl;
	cout << "distances: ";											//ответ
	for (int i = 0; i < n; i++) cout << d[i] << ' ';
	cout << endl;
	cout << "paths" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": ";
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] + 1 << ' ';
		cout << i + 1 << endl;
	}
}


//sample for or graph
//5
//7
//1 2 10
//2 3 50
//3 5 10
//4 3 20
//4 5 60
//1 4 30
//1 5 100
