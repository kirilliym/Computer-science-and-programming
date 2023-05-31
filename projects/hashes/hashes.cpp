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





void openhash()
{
	ifstream in;
	in.open("data base.txt");
	ofstream out;
	out.open("result.txt");
	string s;
	getline(cin, s);
	vector<info> a;
	while (getline(in, s)) a.push_back(getinfo(s));


	/////////////////Making table////////////////////
	cout << "table size = ";
	cin >> mod;
	vector<node *> table(mod, nullptr);
	for (int i = 0; i < a.size(); i++)
		ppush(table[hash1(a[i].money)], a[i]);


	////////////////Printing table//////////////////
	PrintTable(table);


	///////////////Finding & deleting el////////////
	string sur; int mon;
	cout << "surname = "; cin >> sur;
	cout << "money = "; cin >> mon;
	node* cell = table[hash1(mon)];
	node* foundation = ffind(cell, sur);
	cout << "iterator = " << foundation << endl;
	

	if (!foundation) cout << "no such element" << endl;
	else if (cell == foundation)			//begin
	{
		if (cell->next)
		{
			table[hash1(mon)] = cell->next;
		}
		else
		{
			table[hash1(mon)] = nullptr;
		}
	}
	else
	{
		if (foundation->next && foundation->prev)		//center
		{
			foundation->next->prev = foundation->prev;
			foundation->prev->next = foundation->next;
		}
		else
		{
			if (foundation->next)						//end
			{
				foundation->prev = nullptr;
			}
		}
	}

	PrintTable(table);
}



void closehash()
{
	ifstream in;
	in.open("data base.txt");
	ofstream out;
	out.open("result.txt");
	string s;
	getline(cin, s);
	vector<info> a;
	while (getline(in, s)) a.push_back(getinfo(s));

	/////////////////Making table////////////////////
	cout << "table size (>= n) = ";
	cin >> mod;
	vector<int> table(mod, -1);
	for (int i = 0; i < a.size(); i++)
	{
		int j = 0;
		while (true)
		{
			if (table[hash2(a[i].money, j)] == -1)
			{
				table[hash2(a[i].money, j)] = i;
				break;
			}
			else
			{
				j++;
			}
		}
	}


	for (int i = 0; i < table.size(); i++)
	{
		cout << i << ':';
		if (table[i] != -1) PrintInfo(a[table[i]]);
		cout << endl;
	}


	///////////////Finding el////////////////////
	string sur; int mon;
	cout << "surname = "; cin >> sur;
	cout << "money = "; cin >> mon;
	int j = 0;
	vector<int> used(mod, 0);
	while (true)
	{
		if (used[hash2(mon, j)]) break;
		used[hash2(mon, j)] = 1;
		if (a[table[hash2(mon, j)]].surname == sur)
		{
			cout << "element's index = " << hash2(mon, j) << endl;
			return;
		}
		else j++;
	}
	cout << "no such element" << endl;
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


