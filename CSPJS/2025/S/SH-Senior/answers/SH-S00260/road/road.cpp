#include <bits/extc++.h>

template <typename T>
inline void Read(T &x) {
	char ch;
	for (x = 0; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
}

template <typename T, typename... Tr>
inline void Read(T &x, Tr &... rest) {
	Read(x), Read(rest...);
}
template <typename T>
inline void ChkMin(T &x, const T &y) {
	if (x > y) x = y;
}
constexpr int MaxK = 15, MaxN = 1e4 + MaxK, MaxM = 1e6 + MaxK, MaxE = MaxM, MaxV = MaxN;
int n, m, k, c[MaxK];
struct Edge {
	int v, w;
};
std::vector<Edge> graph[MaxV];
inline void AddEdge(int u, int v, int w) {
	graph[u].push_back({v, w});
	graph[v].push_back({u, w});
}

int64_t dis[MaxV];
char vis[MaxV];
using pli = std::pair<int64_t, int>;	// dis, id
__gnu_pbds::priority_queue<pli, std::greater<pli>> pq;
decltype(pq)::point_iterator it[MaxV];
void SolvePrim() {
	for (int i = 1, u, v, w; i <= m; i++)
		Read(u, v, w), AddEdge(u, v, w);
	for (int i = 0; i < k; i++) {
		Read(c[i]);
		for (int j = 1, w; j <= n; j++)
			Read(w), AddEdge(i + n + 1, j, w);
	}
	int64_t min = 1e18;
	for (int i = 0; i < 1 << k; i++) {
		int64_t ans = 0; bool jump = false;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) ans += c[j];
			else if (!c[j]) {
				jump = true; break;
			}
		}
		if (jump) continue;
		pq.clear();
		memset(vis, 0, sizeof(vis));
		memset(dis, 0x3f, sizeof(dis)), dis[1] = 0;
		for (int i = 1; i <= n + k; i++)
			it[i] = pq.push({dis[i], i});
		while (!pq.empty()) {
			auto u = pq.top().second;
			pq.pop(); vis[u] = 1;
			if (u <= n || (i & (1 << u - n - 1))) ans += dis[u];
			for (auto &&[v, w] : graph[u]) {
				if (vis[v]) continue;
				if (v > n && !(i & (1 << v - n - 1))) continue;
				if (dis[v] > w)
					pq.modify(it[v], {dis[v] = w, v});
			}
		}
		ChkMin(min, ans);
	}
	printf("%ld\n", min);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	Read(n, m, k);
	SolvePrim();
	return 0;
}