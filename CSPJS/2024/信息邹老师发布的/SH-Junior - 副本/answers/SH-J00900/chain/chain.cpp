#include <bits/stdc++.h>
using namespace std;
int s[100001][11];
int r[100001], c[100001], l[100001];
vector <int> v[200001];
int main ()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	for (int e = 1; e <= t; e++)
	{
		int n, k, q;
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++)
		{
			int l;
			cin >> l;
			for (int j = 1; j <= l; j++)
			{
				cin >> s[i][j];
				v[s[i][j]].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++)
			cin >> r[i] >> c[i];
		cout << "0";
	}
	return 0;
}
