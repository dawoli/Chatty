#include<bits/stdc++.h>
using namespace std;

set<string> s;
string st;

int main()
{
	ios::sync_with_stdio(false);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> st;
		s.insert(st);
	}
	
	cout << 52 - int(s.size());
}
