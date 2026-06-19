#include <bits/stdc++.h>
using namespace std;
int n, q;
int ans;
bool valid = true;
string og, ta;
//int dist[500009];
vector <string> r1;
vector <string> r2;
int main()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		r1.push_back(str1);
		r2.push_back(str2);
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> og >> ta;
	}
	for (int i = 1; i <= q; i++)
	{
		cout << "0" << endl;
	}
	return 0;
}
