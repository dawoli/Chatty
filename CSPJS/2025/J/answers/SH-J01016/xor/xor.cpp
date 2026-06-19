#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
long long pre[500005];
vector<pair<int, int>> vis;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int l = 1, r; l + i - 1 <= n; l++)
		{
			r = l + i - 1;
			bool visited = 0;
			for (auto j : vis)
			{
				if (!((l < j.first && r < j.first) || (l > j.second && r > j.second)))
				{
					visited = 1;
					break;
				}
			}
			if ((pre[r] ^ pre[l - 1]) == k && !visited)
			{
				cnt++;
				vis.push_back({l, r});
			}
		}
	}
	cout << cnt;
	return 0;
}
