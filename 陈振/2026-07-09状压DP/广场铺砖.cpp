#include <bits/stdc++.h>
#define ll long long
#define maxn 16
using namespace std;
ll	f[maxn][1 << maxn];
ll	fl[maxn];
int main()
{
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < (1 << m); i++)
	{
		bool cnt = 0, odd = 0;
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
				odd |= cnt, cnt = 0;
			else
				cnt ^= 1;
			fl[i] = odd | cnt ? 0 : 1;
		}
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < (1 << m); j++)
		{ // i行的状态
			f[i][j] = 0;
			for (int k = 0; k < (1 << m); k++)
			{ // i-1行的状态﹔
				// 不冲突，没有奇数个0
				if (!(j & k) && fl[j | k])
					f[i][j] += f[i - 1][k];
			}
		}
	}
	cout << f[n][0] << endl;
	return 0;
}