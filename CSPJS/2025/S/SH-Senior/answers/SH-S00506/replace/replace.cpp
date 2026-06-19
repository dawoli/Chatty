#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int>> bullll[10000005]; // x + 5000002
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		int l = 0, r = 0;
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] == 'b')
			{
				l = j;
				break;
			}
		}
		for (int j = 0; j < b.length(); j++)
		{
			if (b[j] == 'b')
			{
				r = j;
				break;
			}
		}
		bullll[r - l + 5000002].push_back({max(l, r), max(a.length() - l - 1, b.length() - r - 1)});
	}
	for (int i = 1; i <= m; i++)
	{
		string a, b;
		cin >> a >> b;
		int lx = 0, rx = 0;
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] == 'b')
			{
				lx = j;
				break;
			}
		}
		for (int j = 0; j < b.length(); j++)
		{
			if (b[j] == 'b')
			{
				rx = j;
				break;
			}
		}
		int ans = 0;
		for (auto u : bullll[rx - lx + 5000002])
			ans += ((u.first <= max(lx, rx) && u.second <= max(a.length() - lx - 1, b.length() - rx - 1)) ? 1 : 0);
		cout << ans << endl;
	}
	return 0;
} 
 
