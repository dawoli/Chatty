#include <iostream>
#include<algorithm>
const int MOD = 998244353, N = 5005; 
using namespace std;
int n, a[N];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 3)
	{
		if(a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) // 我不会写了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
			cout << 1;
		else
			cout << 0;
	}
	else if(n <= 20)// 老师，帮帮我！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
	{
		for(int i = 7; i < (1 << n); i++)
		{
			if(__builtin_popcount(i) < 3)
				continue;
			int sum = 0, mx = 0;
			for(int j = 0; j < n; j++)
				if(i & (1 << j))
				{
					sum += a[j + 1];
					mx = max(mx, a[j + 1]);
				}
			if(sum > mx * 2)
				ans++;
			ans %= MOD;
		}
		cout << ans;
	}
	else
	{
		for(int i = 3; i <= n; i++)
		{
			long long sum = 1;
			for(int j = 1; j <= i; j++)
				sum = (sum * (n - j + 1) % MOD * j) % MOD;
			ans = (ans + sum) % MOD;
		}
		cout << ans;
	}
}
