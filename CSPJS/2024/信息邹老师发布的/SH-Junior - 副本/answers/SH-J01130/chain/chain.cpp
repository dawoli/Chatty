#include <bits/stdc++.h>
using namespace std;
int s[100005];
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int sum = 0;
		int n, k, q;
		cin >> n >> k >> q;
		for (int j = 0; j < n; j++)
		{
			int l;
			for (int z = 0; z < l; z++)
			{
				cin >> s[z];
				sum += s[z];
				sum %= 2;
			}
		}
		for (int j = 0; j < q; j++)
		{
			int r, c;
			cin >> r >> c;
			if (sum == (r * c + q) % 2) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
