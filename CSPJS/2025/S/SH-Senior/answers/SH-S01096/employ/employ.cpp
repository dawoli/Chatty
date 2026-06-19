#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[600];
int c[600];
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, k = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i]; 
		if(s[i] == '1') k++;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i]; 
	}
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= 998244353;
	}
	if(m > k) 
	{
		cout << 0 << endl;
		return 0;
	}
	if(m == n)
	{
		int flag = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '0') flag = 1;
		}
		if(flag) cout << 0 << endl;
		else cout << ans << endl;
		return 0;
	}
	if(m == 1)
	{
		if(k == 0) cout << 0 << endl;
		else cout << k * ans % 998244353 / n; 
	}
	if(k == n) 
	{
		cout << ans << endl;
		return 0;
	}
	return 0;
}
