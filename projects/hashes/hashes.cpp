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


struct info
{
	string surname;
	string role;
	string birth;
	int worktime;
	int money;
};

struct node
{
	info item;
	node* next;
	node* prev;
};

int mod;
int hash1(int x) { return x % mod; }
int hash2(int x, int i) { return (hash1(x) + i) % mod; }


int main()
{
	cout << "task = ";
	int task; cin >> task;
	switch (task)
	{
	case 1:
		openhash();
		break;
	case 2:
		closehash();
		break;
	default:
		break;
	}
}


