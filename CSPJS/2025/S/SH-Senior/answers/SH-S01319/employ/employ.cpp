#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

char c[505];
int x[505];

using namespace std;

int main()
{
	freopen("employ3.in","r",stdin);
	freopen("employ3.out","w",stdout);
	int m,n;
	cin >> n >> m;
	bool f = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if(c[i] == '0') f = 0;
	}
	if(f)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
			if(x[i] != 0) cnt++;
		}
		long long tans = 0;
		long long ans = 1;
			for(int i = cnt - m + 1;i <= cnt;i++)
			{
				ans *= i;
				ans %= 998244353;
			}
			tans += ans;
			tans %= 998244353;
			ans = 1;
		for(int i = 1;i <= n - cnt;i++)
		{
			ans *= i;
			ans %= 998244353;
		}
		long long bans = ans * tans;
		bans %= 998244353;
		cout << bans <<endl;
	}
	return 0;	
} 
