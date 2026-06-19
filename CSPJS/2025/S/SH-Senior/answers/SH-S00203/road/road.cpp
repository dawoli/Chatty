# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000010;
const int M = 10020;
struct edge {int to, next;ll c;} e[N << 1];
struct node {int x, y, z;};
int n, m, k;
ll c[15], val[M][15];
ll id[M];
int cnt, head[N];
vector <node> ed;
queue <int> q;

void add(int u, int v, ll w) {e[++cnt] = {v, head[u], w}, head[u] = cnt;}

bool cmp(node a, node b) {return a.z < b.z;}

int find(int x) {return (id[x] == x) ? x : id[x] = find(id[x]);}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		ed.push_back({u, v, w});
//		add(u, v, w);
//		add(v, u, w);
	}
	bool isA = false;
	for (int i = 1; i <= k; i++) // n + 1 - n + k; n + k + 1 - n + 2k
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			scanf("%lld", &val[j][i]);
		}
		isA &= (c[i] != 0);
	}
	if (!k)
	{
		for (int i = 1; i <= n; i++)
		{
			id[i] = i;
		}
		sort(ed.begin(), ed.end(), cmp);
		ll ans, cnt;
		ans = cnt = 0;
		for (auto p : ed)
		{
//			cout<<p.x<<" "<<p.y<<" "<<w<<endl;
			int fu, fv, w, xx;
			fu = find(p.x), fv = find(p.y), w = p.z;
			if (fu == fv) continue;
			id[fu] = fv;
			ans += w;
			cnt++;
			if (!k && cnt == n - 1) break;
		}
		printf("%lld\n", ans);
	}
//	cout<<isA<<endl;
	else if (!isA)
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ed.push_back({n + i, j, val[j][i]});
//				add(n + i, j, val[j][i]);
//				add(j, n + i, val[j][i]);
			}
		}
		for (int i = 1; i <= n + k; i++)
		{
			id[i] = i;
			if (i > 1 && i <= n) q.push(i);
		}
		sort(ed.begin(), ed.end(), cmp);
		ll ans;
		ans = 0;
		for (auto p : ed)
		{
//			cout<<p.x<<" "<<p.y<<" "<<w<<endl;
			int fu, fv, xx;
			ll w;
			fu = find(p.x), fv = find(p.y), w = p.z;
			if (fu == fv) continue;
			id[fu] = fv;
			ans += w;
			xx = find(1);
			bool flg;
			flg = true;
			int siz;
			siz = q.size();
			for (int i = 1; i <= siz; i++)
			{
				int t;
				t = q.front(), q.pop();
				if (xx != find(t)) {flg = false; q.push(t); break;}
			}
			if (flg) break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
//40pts
