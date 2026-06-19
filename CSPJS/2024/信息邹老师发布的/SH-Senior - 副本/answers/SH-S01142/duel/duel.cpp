#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 8;
struct node
{
	int pre, next, data;
}g[MAXN];
int cnt[MAXN];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		scanf("%d", &k);
		cnt[k]++;
	}
	int dt = 0;
	for (int i = 1; i <= 1e5 + 1; i++)
	{
		if (cnt[i] >= 1)
		{
			dt++;
			g[dt].data = cnt[i];
			g[dt].pre = dt - 1;
			g[dt].next = dt + 1; 
		}
	}
	int head = 1, rear = dt;
	int ans = 0;
	while (n > 0)
	{
		ans++;
		for (int i = head; i <= rear; i = g[i].next)
		{
			g[i].data--;
			n--;
			if (g[i].data == 0)
			{
				if (i == head) head = g[i].next;
				if (i == rear) rear = g[i].pre;
				g[g[i].next].pre = g[i].pre;
				g[g[i].pre].next = g[i].next;
			}
		}
	}
	cout << ans;
 	return 0;
}
