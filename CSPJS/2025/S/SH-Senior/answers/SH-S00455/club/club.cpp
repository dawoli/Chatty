#include <bits/stdc++.h>
#define il inline
#define N 2000010
using namespace std;
typedef long long ll;

il ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch != '-' && !(ch >= '0' && ch <= '9')) ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
	return x * f;
}
ll _, n;
struct Student {
	ll a[4];
} stu[N];
namespace SOLVEBF {
	ll f[N], cnt[4], ans;
	void dfs(ll x) {
		if (x > n) {
			ll tmp = 0;
			for (int i = 1; i <= n; ++i)
				tmp += stu[i].a[f[i]];
			ans = max(ans, tmp);
			return;
		}
		for (int i = 1; i <= 3; ++i) {
			f[x] = i;
			if(cnt[i] + 1 > n / 2) continue;
			++cnt[i]; dfs(x + 1); --cnt[i];
		}
			
	}
}
il void solveBF() {
	using namespace SOLVEBF;
	ans = 0; dfs(1);
	cout << ans << "\n";
}
namespace SOLVE {
	ll nE, hd[N], s, t, nV;
	ll maxFlow, minCost, dis[N], cur[N];
	bool vis[N];
	struct edge {
		ll to, w, f, nxt;
	} e[N + N];
	il void add(ll u, ll v, ll w, ll f) {
		e[++nE] = (edge){v, w, f, hd[u]};
		hd[u] = nE;
	}
	il bool bfs() {
		for (int i = 1; i <= nV; ++i) vis[i] = false;
		for (int i = 1; i <= nV; ++i) dis[i] = (1ll << 45);
		queue<ll> q; q.push(s); dis[s] = 0; vis[s] = true;
		while (!q.empty()) {
			ll u = q.front(); q.pop();
			vis[u] = false;
//			cout << u << " " << dis[u] << "\n";
			for (int i = hd[u]; i; i = e[i].nxt) {
				ll v = e[i].to;
				if (!e[i].f) continue;
				if (dis[v] > dis[u] + e[i].w) {
					dis[v] = dis[u] + e[i].w;
					if (!vis[v]) vis[v] = true, q.push(v);
				}
			} 
		}
		return (dis[t] != (1ll << 45));
	}
	il ll dfs(ll u, ll Flow) {
//		cout << u << "\n"; 
		vis[u] = true;
		ll Ans = 0;
		if(u == t) return Flow;
		for (int i = cur[u]; i; i = e[i].nxt) {
			cur[u] = i;
			ll v = e[i].to;
			if (dis[v] != dis[u] + e[i].w || !e[i].f || vis[v])
				continue;
			ll dt = dfs(v, min(Flow, e[i].f));
			Ans += dt; Flow -= dt;
			e[i].f -= dt; e[i ^ 1].f += dt;
		}
		return Ans;
	}
	il void Dinic() {
		nV = n + 5;
		s = nV - 1; t = nV;
		maxFlow = minCost = 0;
		ll oT = 0, pT = 0;
		while(bfs()) {
			double ST = clock();
//			cout << "114\n";
//			return;
			for (int i = 1; i <= nV; ++i)
				cur[i] = hd[i];//, vis[i] = false;
			ll dt = dfs(s, (1ll << 45));
			minCost += dt * dis[t];
			maxFlow += dt;
//			cout << "\n-----------------\n";
//			for (int u = 1; u <= n + 5; ++u)
//				for (int i = hd[u]; i; i = e[i].nxt)
//					cout << u << " " << e[i].to << " " << e[i].w << " " << e[i].f << "\n";
//			cout << "\n-----------------\n";
			oT += clock() - ST; ++pT;
			cerr << oT << " " << pT << "\n"; 
		}
	}
}

il void solve() {
	using namespace SOLVE;
	nE = 1;
	for (int i = 1; i <= n + 5; ++i) hd[i] = 0;
	for (int i = 1; i <= n; ++i) {
		add(n + 4, i, 0, 1);
		add(i, n + 4, 0, 0);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			add(i, n + j, -stu[i].a[j], 1);
			add(n + j, i, stu[i].a[j], 0);
		}
	}
	for (int i = 1; i <= 3; ++i) {
		add(n + i, n + 5, 0, n / 2);
		add(n + 5, n + i, 0, 0);
	}
//	for (int u = 1; u <= n + 5; ++u)
//		for (int i = hd[u]; i; i = e[i].nxt)
//			cout << u << " " << e[i].to << " " << e[i].w << " " << e[i].f << "\n";
//	return;
	Dinic();
	cout << -minCost << "\n";
}
namespace SOLVE0 {
	ll Min(ll d1, ll d2, ll d3) {
		return min(d1, min(d2, d3));
	}
	ll sMin(ll d1, ll d2, ll d3) {
		return d1 + d2 + d3 - max(d1, max(d2, d3)) - min(d1, min(d2, d3));
	}
	struct node {
		ll id, d1, d2, d3;
		
		bool operator < (const node &p) const {
			if (Min(d1, d2, d3) != Min(p.d1, p.d2, p.d3)) Min(d1, d2, d3) > Min(p.d1, p.d2, p.d3);
			return sMin(d1, d2, d3) > sMin(p.d1, p.d2, p.d3);
		}
	};
	priority_queue<node> pq[4];
	ll S[4];
}
void solve0() {
	using namespace SOLVE0;
	ll Ans = 0;
	for (int i = 1; i <= 3; ++i)
		while(!pq[i].empty()) pq[i].pop();
	
	for (int i = 1; i <= n; ++i) {
//		cout << stu[i].a[1] << " " << stu[i].a[2] << " " << stu[i].a[3] << "\n";
		if (stu[i].a[1] > stu[i].a[2] && stu[i].a[1] > stu[i].a[3])
			Ans += stu[i].a[1], pq[1].push((node){i, (1ll << 45), stu[i].a[1] - stu[i].a[2], stu[i].a[1] - stu[i].a[3]});
		if (stu[i].a[2] > stu[i].a[1] && stu[i].a[2] > stu[i].a[3])
			Ans += stu[i].a[2], pq[2].push((node){i, stu[i].a[2] - stu[i].a[1], (1ll << 45), stu[i].a[2] - stu[i].a[3]});
		if (stu[i].a[3] > stu[i].a[1] && stu[i].a[3] > stu[i].a[2])
			Ans += stu[i].a[3], pq[3].push((node){i, stu[i].a[3] - stu[i].a[1], stu[i].a[3] - stu[i].a[2], (1ll << 45)});
	}
	S[1] = pq[1].size(), S[2] = pq[2].size(), S[3] = pq[3].size();
//	cout << S[1] << " " << S[2] << " " << S[3] << "\n";
	if (S[1] > n / 2) {
		while (S[1] > n / 2) {
			node u = pq[1].top(); pq[1].pop(); --S[1];
//			cout << u.id << " " << u.d1 << " " << u.d2 << " " << u.d3 << "\n";
			if (Min(u.d1, u.d2, u.d3) == u.d2 && S[2] < n / 2) Ans -= Min(u.d1, u.d2, u.d3), pq[2].push(u), ++S[2];
			else if (Min(u.d1, u.d2, u.d3) == u.d3 && S[3] < n / 2) Ans -= Min(u.d1, u.d2, u.d3), pq[3].push(u), ++S[3];
			else if (Min(u.d1, u.d2, u.d3) == u.d2 && S[2] >= n / 2) Ans -= sMin(u.d1, u.d2, u.d3), pq[3].push(u), ++S[3];
			else if (Min(u.d1, u.d2, u.d3) == u.d3 && S[3] >= n / 2) Ans -= sMin(u.d1, u.d2, u.d3), pq[2].push(u), ++S[2];
		}
//		cout << Ans << "\n";
//		cout << S[1] << " " << S[2] << " " << S[3] << "\n";
	}
	if (S[2] > n / 2) {
		while (S[2] > n / 2) {
			node u = pq[2].top(); pq[2].pop(); --S[2];
			if (Min(u.d1, u.d2, u.d3) == u.d1 && S[1] < n / 2) Ans -= Min(u.d1, u.d2, u.d3), pq[1].push(u), ++S[1];
			else if (Min(u.d1, u.d2, u.d3) == u.d3 && S[3] < n / 2) Ans -= Min(u.d1, u.d2, u.d3), pq[3].push(u), ++S[3];
			else if (Min(u.d1, u.d2, u.d3) == u.d1 && S[1] >= n / 2) Ans -= sMin(u.d1, u.d2, u.d3), pq[3].push(u), ++S[3];
			else if (Min(u.d1, u.d2, u.d3) == u.d3 && S[3] >= n / 2) Ans -= sMin(u.d1, u.d2, u.d3), pq[1].push(u), ++S[1];
		}
//		cout << Ans << "\n";
//		cout << S[1] << " " << S[2] << " " << S[3] << "\n";
	}
	if (S[3] > n / 2) {
		while (S[3] > n / 2) {
			node u = pq[3].top(); pq[3].pop(); --S[3];
			if (Min(u.d1, u.d2, u.d3) == u.d1 && S[1] < n / 2) Ans -= Min(u.d1, u.d2, u.d3), pq[1].push(u), ++S[1];
			else if (Min(u.d1, u.d2, u.d3) == u.d2 && S[2] < n / 2) Ans -= Min(u.d1, u.d2, u.d3), pq[2].push(u), ++S[2];
			else if (Min(u.d1, u.d2, u.d3) == u.d1 && S[1] >= n / 2) Ans -= sMin(u.d1, u.d2, u.d3), pq[2].push(u), ++S[2];
			else if (Min(u.d1, u.d2, u.d3) == u.d2 && S[2] >= n / 2) Ans -= sMin(u.d1, u.d2, u.d3), pq[1].push(u), ++S[1];
		}
//		cout << Ans << "\n";
//		cout << S[1] << " " << S[2] << " " << S[3] << "\n";
	}
	cout << Ans << "\n";
//	cout << S[1] << " " << S[2] << " " << S[3] << "\n";
}
il void Solve() {
	n = read();
	for (int i = 1; i <= n; ++i)
		stu[i].a[1] = read(), stu[i].a[2] = read(), stu[i].a[3] = read();
	if (n <= 10) solveBF();
	else
	    solve();
//	else
//		solve0();
}

int main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	ll _; _ = read();
	while (_--) Solve();
	
	return 0;
}
