#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
using namespace std;
ll n, m, k, ans;
struct node
{int u, v, w;}rd[1000006];
int f[10004];
int fd(int x)
{
	if(f[x] == x)
		return x;
	f[x] = fd(f[x]);
	return f[x];
}
void uni(int x, int y){f[fd(y)] = fd(x);}
bool cmp(node a, node b){return a.w < b.w;}
int main()
{
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if(k)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &rd[i].u, &rd[i].v, &rd[i].w);
	for(int i = 1; i <= n; i++)
		f[i] = i;
	sort(rd + 1, rd + m + 1, cmp);
	int num = 0;
	for(int i = 1; num < n - 1; i++)
		if(fd(rd[i].u) != fd(rd[i].v))
			num++, ans += rd[i].w, uni(rd[i].u, rd[i].v);
	cout << ans;
	return 0;
}

