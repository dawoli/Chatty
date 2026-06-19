#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans = 1;
string s;
int c[505];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	t = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] == 0) t -= 1;
	}
	if (t < m) cout << 0;
	else
	{
		for (int i = 1; i <= t; i++) ans *= i;
		cout << ans % 998244353 << endl;
	} 
	return 0; 
} 
