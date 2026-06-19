#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int bas[100010] , a[100010] , c[100010] , g[20][100010];

int L2(int x)
{
	int cnt = 0;
	for (int a = 1; ; a *= 2)
	{
		if (a > x) return cnt;
		cnt++;
	}
}

int main()
{
	freopen("arena.in" , "r" , stdin);
	freopen("arena.out" , "w" , stdout);
	int n , q , T;
	scanf("%d%d" , &n , &q);
	for (int i = 1; i <= n; i++) scanf("%d" , &bas[])
	for (int i = 1; i <= q; i++) scanf("%d" , &c[i]);
	int k = L2(n);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= (1 << (k - i)); j++)
		{
			scanf("%1d" , &g[i][j]);
		}
	}
	cin >> T;
	while (T--)
	{
		int x[5];
		scanf("%d%d%d%d" , &x[0] , &x[1] , &x[2] , &x[3]);
		for (int i = 1; i <= n; i++)
		{
			a[i] = bas[i] ^ x[i % 4];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			/**/;
			ans ^= i * sum;
		}
		cout << ans << endl;
	}
	return 0;
}