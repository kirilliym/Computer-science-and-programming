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

	int v1 = -1, v2 = -1;
	int f = 0;
	for (int i = 0; i < n; ++i)									//нахождение нечетных вершин 
	{
		if (g[i].size() % 2 == 1)
		{
			if (v1 == -1)
			{
				v1 = i;
			}
			else if (v2 == -1)
			{
				v2 = i;
			}
			else
			{
				f = 1;
				break;
			}
		}
	}

	if (f || v1 != -1 && v2 == -1)								//если нечетных больше чем 2 или 1 то путь не сущ.
	{
		cout << f << ' ' << v1 << ' ' << v2 << endl;
		cout << "no Eller's path" << endl;
		return 1;
	}


}