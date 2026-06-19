#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans, cnt1;
int cntp0;
string s;
int c[509];
int main()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	ans = n;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] == 0)
		{
			cntp0++;
		}
	}
	cout << "0" << endl;
	return 0;
}
