#include<bits/stdc++.h>
using namespace std;
string chain[200010], r[200010], c[200010];
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n, k, q;
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++)
		{
			int l;
			cin >> l;
			cin >> chain[i];
		}
		for(int i = 1; i <= q; i++)
		{
			cin >> r[i] >> c[i];
			cout << c[i] % 2 << endl;
		}
	}
	return 0;
} 
