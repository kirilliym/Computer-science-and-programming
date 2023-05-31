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

int main() {
    
	cout << "n = ";
	int n; cin >> n;
	cout << "m = ";
	int m; cin >> m;
	vector<set<int>>g(n);
	for (int i = 0; i < m; i++)									//считывание графа
	{
		cout << "m[" << i + 1 << "] (u v) = ";
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}


}