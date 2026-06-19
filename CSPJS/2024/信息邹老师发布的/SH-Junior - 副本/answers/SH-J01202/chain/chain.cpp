#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int t, n, k, q, x, l, a, b, c[200005];
signed main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		memset(c, 0, sizeof c);
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++)
		{
			cin >> l;
			for(int j = 1; j <= l; j++)
			{
				cin >> x;
				c[x]++;
			}
		}
		while(q--)
		{
			cin >> a >> b;
			if(!c[b])cout << 0 << endl;
			cout << 1 << endl;
		}
	}
 }
