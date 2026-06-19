#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, ans, a[N], tot;
struct Node
{
	int l, r, x, cnt1, cnt2;
} b[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int r;
		cin >> r;
		a[r]++;
	}
	b[0].r = 1;
	for (int i = 1; i <= 1e5; i++)
	{
		if (a[i] != 0)
			b[++tot] = {tot - 1, tot + 1, i, a[i], a[i]};
	}
	for (int j = 1; j <= 100000; j++)
	for (int i = b[0].r; b[i].r != tot + 1;	i = b[i].r)
	{
		int minn = min(b[b[i].r].cnt2, b[i].cnt1);
		b[i].cnt1 -= minn;
		b[b[i].r].cnt2 -= minn;
		if (b[i].cnt1 == 0)
		{
			b[b[i].r].l = b[i].l;
			b[b[i].l].r = b[i].r;
		}
	}
	for (int i = b[0].r; i != tot + 1;	i = b[i].r)
		ans += b[i].cnt1;
	cout << ans;
}
