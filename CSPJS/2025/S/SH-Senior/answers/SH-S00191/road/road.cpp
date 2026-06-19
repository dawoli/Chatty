#include <bits/stdc++.h>
using namespace std; 
//正常 prim 16pts
//狂野 prim ???
#define ll long long
ll n, m, k, cnt; 
struct edge
{
	ll idx, type, val, u, v;
}; 
edge a[2000009]; 
ll fx[19][10009], bd[10009], is_build[19]; 
queue<edge> q; 
struct cmp //????? 
{
	bool operator() (edge& x, edge& y)
	{
		ll vx = x.val+(x.type==1&&!is_build[x.idx]? bd[x.u]: 0), 
		vy = y.val+(y.type==1&&!is_build[y.idx]? bd[y.u]: 0); 
		return vx > vy; 
	}
}; 
priority_queue<edge, vector<edge>, cmp> pq; 
struct bfset //非常正常的并查集 
{
	vector<ll> fa, size; 
	void init (ll x)
	{
		fa.clear(); 
		for (int i = 0; i < x; i++)
		{
			fa.push_back(i); 
			size.push_back(1); 
		}
	}
	ll find (ll x)
	{
		if (fa[x] == x) return x; 
		return fa[x] = find(fa[x]); 
	}
	ll check (ll x, ll y)
	{
		return find(x) == find(y); 
	}
	void merge (ll x, ll y)
	{
		if (check(x,y)) return; 
		x = find(x), y = find(y); 
		if (size[x]<size[y]) swap(x,y); 
		fa[y] = x; 
		size[x] += size[y]; 
	}
};
bfset s; 
ll prim0 () //正常的prim 
{
	s.init(n); 
	ll ans = 0; 
	while (!pq.empty())
	{
		edge e = pq.top(); 
		ll x = e.u, y = e.v; 
		pq.pop(); 
		if (s.check(x,y)) continue; 
		s.merge(x,y); 
		ans += e.val; 
	}
	return ans; 
}
cmp cmp1; 
ll primwild () //狂野的prim，没啥用 
{
	s.init(n+k); 
	ll ans = 0; 
	while (!pq.empty())
	{
		ll x = e.u, y = e.v; 
		if (x<n && s.check(x,y)) continue; 
		s.merge(x,y); 
		ans += e.val+(x>=n&&is_build[x-n]? 0: bd[x-n]); 
		if (x>=n)
		{
			is_build[x-n] = true; 
			while (!pq.empty()) //堆&时间复杂度：我谢谢你  
			{
				q.push(pq.top()); 
				pq.pop(); 
			}
			while (!q.empty()) //省点上移的时间吧，已经没希望了 
			{
				pq.push(q.top()); 
				q.pop(); 
			}
		}
	}
	return ans; 
}
int main ()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	cin >> n >> m >> k; 
	for (ll i = 0; i < m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].val; 
		a[i].type = 0, a[i].idx = i; 
		pq.push(a[i]); 
	}
	cnt=m; 
	for (ll i = 0; i < k; i++)
	{
		cin >> bd[i]; 
		for (ll j = 0; j < n; j++)
		{
			cin >> fx[i][j]; 
			a[cnt].idx = cnt, a[cnt].u = n+i, a[cnt].v = j, 
			a[cnt].type = 1, a[cnt++].val = fx[i][j]; 
		}
	}
	if (k == 0) cout << prim0(); 
	else cout << primwild(); //闻到了评测机的香味  
	return 0; 
} 
