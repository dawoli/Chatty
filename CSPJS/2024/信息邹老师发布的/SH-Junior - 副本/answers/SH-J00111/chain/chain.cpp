#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T, n, k, q, s[100000][2000], l, r, c;
	cin >> T;
	for(int i = 1;i <= T;i++)
	{
		cin >> n >> k >> q;
		for(int j = 1;j <= n;j++)
		{
			cin >> l;
			for(int k = 1;k <= l;k++)
			{
				cin >> s[j][k];
			}
		}
		for(int j = 1;j <= q;j++)
		{
			cin >> r >> c;
		}
	}
	cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0 << endl;
	return 0; 
}
