#include <bits/stdc++.h>
using namespace std;

int T,n,m,k[100010],_a[100010],c[100010],a[100010],w[20][140000],ans;
string D[20];
bool d[20][140000],A = 1;

int main()
{
	freopen("arena2.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(k[0] = 1;(1 << k[0]) <= n;k[0]++);
	if((1 << (k[0] - 1)) == n)
	{
		k[0]--;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> _a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> c[i];
		for(k[i] = 1;(1 << k[i]) <= c[i];k[i]++);
		if((1 << (k[i] - 1)) != c[i])
		{
			A = 0;
		}
	}
	for(int i = 1;i <= k[0];i++)
	{
		cin >> D[i];
		for(int j = 0;j < D[i].length();j++)
		{
			d[i][j + 1] = D[i][j] - '0';
		}
	}
	cin >> T;
	while(T--)
	{
		ans = 0;
		int X[4];
		cin >> X[0] >> X[1] >> X[2] >> X[3];
		for(int i = 1;i <= n;i++)
		{
			a[i] = _a[i] ^ X[i % 4];
			cout << a[i] << " ";
		}
		cout << endl;
		if(A)
		{
			for(int i = 1;i <= n;i++)
			{
				w[0][i] = i;
			}
			if((1 << k[0]) != n)
			{
				k[0]--;
			}
			for(int i = 1;i <= k[0];i++)
			{
				for(int j = 1;j <= (1 << (k[0] - i));j++)
				{
					if(d[i][j])
					{
						w[i][j] = (a[w[i - 1][j * 2]] < i ? w[i - 1][j * 2 - 1] : w[i - 1][j * 2]);
					}
					else
					{
						w[i][j] = (a[w[i - 1][j * 2 - 1]] >= i ? w[i - 1][j * 2 - 1] : w[i - 1][j * 2]);
					}
					cout << w[i][j] << " ";
				}
				cout << endl;
			}
			for(int i = 1;i <= m;i++)
			{
				if(c[i] < n)
				{
					if(d[k[i] + 1][1])
					{
						ans ^= i * (w[k[i]][1] + (c[i] + 1 + (1 << k[0])) * ((1 << k[0]) - c[i]) / 2);
					}
					else if(a[w[k[i]][1]] >= k[i] + 1)
					{
						ans ^= i * w[k[i]][1];
					}
					else
					{
						ans ^= i * ((c[i] + 1 + (1 << k[0])) * ((1 << k[0]) - c[i]) / 2);
					}
				}
				else
				{
					ans ^= i * w[k[i]][1];
				}
			}
			cout << ans;
			continue;
		}
	}
	return 0;
}

