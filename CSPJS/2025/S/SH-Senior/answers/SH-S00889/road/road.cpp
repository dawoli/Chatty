#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc getchar()
#define pc putchar
#define pii pair<int,int>
int read()
{
	int p = 1,x = 0;
	char c = gc;
	while(c < '0' || c > '9')	p == c == '-' ? -1 : 1,c = gc;
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = gc;
	return p * x;
}
template<typename _Tp> void _write(_Tp x) { if(x > 9) _write(x / 10); pc(x % 10 | 48); }
template<typename _Tp> void write(_Tp x) { if(x < 0) x = -x,pc('-'); _write(x); }
template<typename _Tp> void writeln(_Tp x) { write(x); puts(""); }
int n,m,mm,k;
const int N = 1e4 + 20,M = 1e6 + 1e5 + 10;
int u[M],v[M],w[M],c[15],a[15][N];
bool flag[15];
int p[N],sz[N],maxsz = 0,ans = 21e8;
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void unite(int x,int y)
{
	int fx = find(x),fy = find(y);
	// fx -> fy
	sz[fy] += sz[fx];
	maxsz = max(maxsz,sz[fy]);
	p[fx] = fy;
}
int solve(int add)
{
	mm = m;
	int cnt = 0,ans = 0;
	for(int i = 1;i <= k;i++)
		if(flag[i])
		{
			ans += c[i];
			for(int j = 1;j <= n;j++)
			{
				mm++;
				u[mm] = n + i; v[mm] = j; w[mm] = a[i][j];
			}
		}

	for(int i = 1;i <= n + k;i++)	p[i] = i;
	priority_queue<pii,vector<pii >,greater<pii > > q; // {w,id}
	for(int i = 1;i <= mm;i++)	q.push((pii){w[i],i});
	while(cnt != n + add - 1 && !q.empty())
	{
		int id = q.top().second; q.pop();
		if(find(u[id]) == find(v[id]))	continue;
		unite(u[id],v[id]);
		cnt++; ans += w[id];
	}
	return ans;
}
void dfs(int step,int add = 0)
{
	if(step == k + 1)
	{
		ans = min(ans,solve(add));
		return;
	}
	dfs(step + 1,add);
	flag[step] = 1;
	dfs(step + 1,add + 1);
	flag[step] = 0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(); m = read(); k = read();
	for(int i = 1;i <= m;i++)
		u[i] = read(),v[i] = read(),w[i] = read();
	int minn = 21e8,maxn = -1;
	for(int i = 1;i <= k;i++)
	{
		c[i] = read();
		maxn = max(maxn,c[i]); minn = min(minn,c[i]);
		for(int j = 1;j <= n;j++)	a[i][j] = read();
	}
	if(k == 0)
	{
		for(int i = 1;i <= n;i++)	p[i] = i;
		priority_queue<pii,vector<pii >,greater<pii > > q; // {w,id}
		for(int i = 1;i <= m;i++)	q.push((pii){w[i],i});
		int cnt = 0,ans = 0;
		while(cnt != n - 1 && !q.empty())
		{
			int id = q.top().second; q.pop();
			if(find(u[id]) == find(v[id]))	continue;
			unite(u[id],v[id]);
			cnt++; ans += w[id];
		}
		writeln(ans);
	}
	else if(minn == 0 && maxn == 0)
	{
		int cnt = 0,ans = 0;
		for(int i = 1;i <= n + k;i++)	p[i] = i;
		for(int i = 1;i <= k;i++)
			for(int j = 1;j <= n;j++)
			{
				m++;
				u[m] = n + i; v[m] = j; w[m] = a[i][j];
			}
		priority_queue<pii,vector<pii >,greater<pii > > q; // {w,id}
		for(int i = 1;i <= m;i++)	q.push((pii){w[i],i});
		int add = 0;
		while(!q.empty() && maxsz != n + add)
		{
			int id = q.top().second; q.pop();
			if(find(u[id]) == find(v[id]))	continue;
			if(u[id] > n)	add++;
			unite(u[id],v[id]);
			cnt++; ans += w[id];
		}
		writeln(ans);
	}
	else
	{
		dfs(1);
		writeln(ans);
	}
	return 0;
}

/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
