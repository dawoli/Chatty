# include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair <ll, ll> P;
# define x first
# define y second

const int N = 1000010;
const int M = 5000010;
struct Tree {ll l, r, tag, sum;} tr[N << 2];
struct node {ll dat, ed, idd;};
ll T, n, m, L, V, ans, ans2, cnt, rt, id, rl;
ll d[N], v[N], a[N], pos[N];
ll dis[M], siz[M], l[M], r[M];
P p[N];
priority_queue <node> q;

bool operator < (node x, node y) {return x.ed > y.ed;}

ll merge(ll u, ll v)
{
//	cout<<u<<" "<<v<<endl;;
	if (!u || !v) return u + v;
	if (siz[u] < siz[v]) swap(u, v);
	r[u] = merge(r[u], v);
	if (dis[l[u]] > dis[r[u]]) swap(l[u], r[u]);
	dis[u] = dis[r[u]] + 1;
	return u;
}

ll del(ll u) {return merge(l[u], r[u]);}

void push_up(ll u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(ll u, ll l, ll r)
{
	tr[u].l = l, tr[u].r = r;
	tr[u].sum = tr[u].tag = 0;
	if (l == r) return;
	ll mid;
	mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void chg(ll u, ll x, ll val)
{
	if (tr[u].l == tr[u].r)
	{
		tr[u].sum += val;
		return;
	}
	ll mid;
	mid = (tr[u].l + tr[u].r) >> 1;
	if (x <= mid) chg(u << 1, x, val);
	else chg(u << 1 | 1, x, val);
	push_up(u);
}

ll ask(ll u, ll l, ll r)
{
 	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	ll mid, res;
	res = 0;
	mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) res += ask(u << 1, l, r);
	if (r > mid) res += ask(u << 1 | 1, l, r);
	return res;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &L, &V);
		build(1, 0, L);
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &d[i], &v[i], &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &pos[i]), chg(1, pos[i], 1);
		ans = ans2 = cnt = 0;
		ll tmp;
		tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > 0)
			{
				if (v[i] > V) ans += (ask(1, d[i], L) > 0), p[++cnt] = {d[i], L};
				else
				{
					ll pos;
					pos = (V * V - v[i] * v[i]);
					if (pos % (a[i] * 2) == 0) pos = d[i] + pos / (a[i] * 2) + 1;
					else pos = d[i] + pos / (a[i] * 2);
					if (pos <= L) ans += (ask(1, pos, L) > 0), p[++cnt] = {pos, L};
				}
			}
			if (a[i] == 0)
			{
				tmp++;
				if (v[i] > V) ans += (ask(1, d[i], L) > 0), p[++cnt] = {d[i], L};
			}
			if (a[i] < 0)
			{
				ll pos;
				pos = (V * V - v[i] * v[i]);
				if (pos % (a[i] * 2) == 0) pos = d[i] + pos / (a[i] * 2) - 1;
				else pos = d[i] + pos / (a[i] * 2);
				if (v[i] > V) ans += (ask(1, d[i], min(L, pos)) > 0), p[++cnt] = {d[i], min(L, pos)};
			}
		}
		if (n <= 3000)
		{
			bool flag;
			for (int i = 1; i <= m; i++)
			{
				flag = true;
	//			if (!flag) break;
				for (int j = 1; j <= cnt; j++)
				{
	//				cout << p[i] << " in " << "(" << l[j] << ", " << r[j] << ")?\n";
					if (p[j].x <= pos[i] && pos[i] <= p[j].y)
					{
						if (ask(1, p[j].x, p[j].y) == 1)
						{
							flag = false;
							break;
						}
					}
				}
				ans2 += flag;
				if (flag) chg(1, pos[i], -1);
			}
		}
		else
		{
			sort(p + 1, p + cnt + 1);
	//		for (int i = 1; i <= cnt; i++) printf("%d %d\n", p[i].x, p[i].y);
			id = 1, rt = M - 1;
			memset(siz, 0, sizeof(siz));
			memset(l, 0, sizeof(l));
			memset(r, 0, sizeof(r));
			siz[rt] = 1e9;
			for (int i = 1; i <= m; i++)
			{
				while (id <= cnt && p[id].x <= pos[i])
				{
					ll tt;
					tt = ask(1, p[id].x, p[id].y);
					q.push({siz[id] = tt + ans2, p[id].y, id});
					rt = merge(rt, id);
					id++;
				}
	//			cout<<"!";
	//			if (!q.empty()) cout << q.top().ed << " " << pos[i] << endl;
				while (!q.empty() && q.top().ed < pos[i])
				{
	//				cout<<"llalalaal";
	//				rl = -1;
	//				find(rt, q.top().idd);
	//				cout << rl << " " << q.top().idd << endl;
	//				del(rl);
					rt = del(q.top().idd);
					q.pop();
				}
	//			cout<<"?";
	//			cout << siz[rt] << endl;
				ans2 += (siz[rt] > ans2);
			}
		}
		printf("%d %d\n", ans, ans2);
	}
	return 0;
}
