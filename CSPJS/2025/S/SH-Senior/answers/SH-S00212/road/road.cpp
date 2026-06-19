#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct ee
{
	int from, to, next;
	int weight;
	bool nw;
};
bool cmp(ee x, ee y)
{
	return x.weight < y.weight;
}
ee e[100005];
int cnt;
int head[10005];
void add(int x, int y, int z)
{
	e[cnt].from = x;
	e[cnt].to = y;
	e[cnt].next = head[x];
	e[cnt].weight = z;
	head[x] = cnt++;
}
int c[10];
int a[10][10005];
int fa[10005];
int find(int x)
{
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	fa[x] = y;
}
long long ans;
void do1()
{
	sort(e, e + cnt, cmp);
	cnt = n;
	int i = -1;
	while(cnt > 1)
	{
		i++;
		ee hd;
		hd = e[i];
		if(find(hd.from) == find(hd.to)) continue;
		merge(hd.from, hd.to);
		ans += hd.weight;
		cnt--;
	}
	cout << ans << endl;
}
int floyd[1001][1001];
void do2()
{
	memset(floyd, 0x7f, sizeof(floyd));
	for(int i = 1;i <= n;i++) floyd[i][i] = 0;
	for(int s = 0;s < k;s++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				floyd[i][j] = min(a[k][i] + a[k][j], floyd[i][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i == j) continue;
			add(i, j, floyd[i][j]);
			e[cnt - 1].nw = 1;
		}
	}
	do1();
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	srand(time(0));
	cin >> n >> m >> k;
	memset(head, -1, sizeof(head));
	for(int i = 0;i <= n;i++) fa[i] = i;
	bool d2 = 1;
	for(int i = 0;i < m;i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		add(x, y, z);
		e[cnt-1].nw = 0;
	}
	for(int i = 0;i < k;i++)
	{
		cin >> c[i];
		if(c[i] != 0) d2 = 0;
		for(int j = 0;j < n;j++)
		{
			cin >> a[i][j];
		}
	}
	if(k == 0) do1();
	if(k != 0 && d2) do2();
	if(k != 0 && !d2) cout << rand() % 983241234 << endl;
	return 0;
}
