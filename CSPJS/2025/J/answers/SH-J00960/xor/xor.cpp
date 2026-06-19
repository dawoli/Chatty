#include <bits/stdc++.h>
#define int128 unsigned long long
using namespace std;
int128 a[500001];
struct item
{
	int128 s, e;
	bool chosen;
} f[500001];
bool cmp (item lhs, item rhs)
{
	if (lhs.e - lhs.s != rhs.e - rhs.s)
		return lhs.e - lhs.s < rhs.e - rhs.s;
	return lhs.s < rhs.s;
}
bool overlap (int128 is, int128 ie, int128 js, int128 je)
{
	return (is <= js && js <= ie && ie <= je) ||
		   (js <= is && is <= je && je <= ie) ||
		   (js <= is && ie <= je) ||
		   (is <= js && je <= ie);
}
set <int128> temp;
int main ()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int128 n, m, cnt = 1;
	cin >> n >> m;
	for (int128 i = 1; i <= n; i++)
		cin >> a[i];
	for (int128 i = 1; i <= n; i++)
	{
		for (int128 j = i; j <= n; j++)
		{
			int128 s = a[i];
			if (i != j)
			{
				for (int128 k = i + 1; k <= j; k++)
					s = s ^ a[k];
			}
			if (s == m)
				f[cnt].s = i, f[cnt++].e = j;
		}
	}
	cnt--;
	sort(f + 1, f + cnt + 1, cmp);
	int128 ans = 0;
	for (int128 i = 1; i <= cnt; i++)
	{
		bool flag = true;
		for (int128 j = i - 1; j >= 1; j--)
		{
			if (overlap(f[i].s, f[i].e, f[j].s, f[j].e) && f[j].chosen)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			f[i].chosen = true;
			ans++;
			temp.insert(i);
		}
	}
	cout << ans;
	return 0;
} 
