#include <bits/stdc++.h>
using namespace std;
set<string> a;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		a.insert(s);
	}
	cout << 52 - a.size();
	return 0;
}
