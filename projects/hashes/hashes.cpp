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


info getinfo(string s)
{
	vector<string> a;
	info res;
	string str;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == ' ')
		{
			a.push_back(str);
			str = "";
		}
		else
		{
			str += s[i];
		}
	}
	if (str.size()) a.push_back(str);

	if (a.size() != 5)
	{
		cout << "Somethin went wrong" << endl;
		exit(0);
	}

	res.surname = a[0];
	res.role = a[1];
	res.birth = a[2];
	res.worktime = stoi(a[3]);
	res.money = stoi(a[4]);
	return res;
}

void PrintInfo(info x)
{
	cout << x.surname << ' ' << x.role << ' ' << x.birth << ' ' << x.money << endl;
}

void PrintTable(vector<node *> &table)
{
	cout << "TABLE" << endl;
	for (int i = 0; i < table.size(); i++)
	{
		cout << i << ':' << endl;
		node *x = table[i];
		while (x != nullptr)
		{
			PrintInfo(x->item);
			x = (*x).next;
		}
		cout << endl;
	}
}


void ppush(node*& a, info x)
{
	node* p = new node;
	p->item = x;
	p->next = p->prev = nullptr;
	if (a == nullptr)
	{
		a = p;
	}
	else
	{
		node* y = a;
		while (y->next)
		{
			y = y->next;
		}
		y->next = p;
		p->prev = y;
	}
}


node* ffind(node* a, string s)
{
	while (a)
	{
		if (a->item.surname == s)
		{
			return a;
		}
		a = a->next;
	}
	return nullptr;
}



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


