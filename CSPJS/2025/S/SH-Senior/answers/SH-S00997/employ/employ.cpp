#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
int n, m;
string s;
int c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	bool fl, fla;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if(c[i] != 1) fl = true;
	}
	sort(c+1, c+n+1);
	if(fl == false)
	{
		int num = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '1') num++;
			else break;
		}
		if(num < m)
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			ll mul = 1;
			for(int i = 1; i <= n; i++)
			{
				mul = (mul*i)%mod;
			}
			cout << mul << endl;
			return 0;
		}
	}
	if(m == 1)
	{
		int num = 0, cnt = 0;
		ll mul = 1;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '0') num++;
			else {num++; break;}
		}
		if(num == n && s[n-1] == '0')
		{
			cout << 0 << endl;
			return 0;
		}
		for(int i = 1; i <= n; i++)
		{
			if(c[i] >= num) cnt++;
		}
		for(int i = 1; i < n; i++)
		{
			mul = (mul*i)%mod;
		}
		cout << mul*cnt%mod << endl;
	}
	
	return 0;
}
