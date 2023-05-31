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
vector<vector<int>>g;
vector<int> used, ans;


int main() {

	cout << "n = ";
	int n; cin >> n;
	g.resize(n); used.assign(n, 0);
	cout << "m = ";
	int m; cin >> m;
	for (int i = 0; i < m; i++)									//считывание графа
	{
		cout << "m[" << i + 1 << "] (u->v) = ";
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}

	for (int i = 0; i < n; i++)									//запускаем дфс из непосещенных вершин
	{
		if (!used[i]) dfs(i);
	}
	
	cout << "topsort: ";										//вывод ответа
	for (int i = n - 1; i >= 0; i--) cout << ans[i] + 1 << ' ';
	cout << endl;
}