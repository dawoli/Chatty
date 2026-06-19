#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

//用于不相交集合的数据结构 
struct SetNode {
	int idx;
	int parent;
} nodes[10004];

SetNode& find_set(SetNode& node) {
	if (node.parent == 0) {
		return node;
	}
	int idx = node.parent;
	while(true) {
		if (nodes[idx].parent == 0) {
			break;
		}
		idx = nodes[idx].parent;
	}
	return nodes[idx];
}
void merge_set(SetNode& a, SetNode& b) {
	b.parent = find_set(a).idx;
}

int n, m, k;
//int map[10004][10004];
pair<int, int> country_dis[10004][10004];
bool occ[10004];
struct Country {
	int a[10004];
	int cost;
	bool built;
} c[14];
struct Edge {
	int u, v, w;
	bool operator < (Edge& e) {
		return w < e.w;
	}
};
deque<Edge> city_edges;
deque<pair<Edge, int>> country_edges;

bool cmp(pair<Edge, int>& a, pair<Edge, int>& b) {
	return a.first.w < b.first.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	memset(country_dis, 0x3f, sizeof(country_dis));
	//memset(map, 0x3f, sizeof(map));
	for (int i = 1; i <= n; i++) {
		nodes[i].idx = i;
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
	//	map[u][v] = w;
	//	map[v][u] = w;
		city_edges.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &(c[i].cost));
		for (int j = 1; j <= n; j++) {
			scanf("%d", &(c[i].a[j]));
		}
		for (int u = 1; u < n; u++) {
			for (int v = u + 1; v <= n; v++) {
				if (country_dis[u][v].first > c[i].a[u] + c[i].a[v]) {
					country_dis[u][v].first = country_dis[v][u].first = c[i].a[u] + c[i].a[v];
					country_dis[u][v].second = country_dis[v][u].second = i;
				}
				pair<Edge, int> uv;
				//uv.first = {u, v, country_dis}; uv.second = v;
				country_edges.push_back({{u, v, country_dis[u][v].first + c[i].cost}, i});
			}
		}
	}
	sort(city_edges.begin(), city_edges.end());
	sort(country_edges.begin(), country_edges.end(), cmp);
	int lasting = n, ans = 0;
	while (lasting > 0 && !city_edges.empty()) {
		Edge edge1 = city_edges.front();
		Edge edge2 = country_edges.front().first;
		int idx = country_edges.front().second;
		
		while(find_set(nodes[edge1.u]).idx == find_set(nodes[edge1.v]).idx) {
			city_edges.pop_front();
			edge1 = city_edges.front();
		}
		while(find_set(nodes[edge1.u]).idx == find_set(nodes[edge1.v]).idx) {
			country_edges.pop_front();
			edge2 = country_edges.front().first;
			idx = country_edges.front().second;
		}
		
		int build_cost = 0;
		if (!c[country_dis[edge2.u][edge2.v].second].built) {
			build_cost = c[country_dis[edge2.u][edge2.v].second].cost;
		}
		//printf("u=%d v=%d cu=%d cv=%d w=%d cw+bc=%d\n", edge1.u, edge1.v, edge2.u, edge2.v, edge1.w, edge2.w);
		Edge final;
		edge2.w -= build_cost;
		if (edge2.w + build_cost < edge1.w) {
			final = edge2;
			final.w += build_cost;
			if (!c[country_dis[edge2.u][edge2.v].second].built) {
				for (int i = 0; i < country_edges.size(); i++) {
					if (country_edges[i].second == idx) {
						country_edges[i].first.w -= c[idx].cost;
					}
				}
				sort(country_edges.begin(), country_edges.end(), cmp);
			}
			c[country_dis[edge2.u][edge2.v].second].built = true;
			country_edges.pop_front();
		//	printf("country\n");
		} else {
			final = edge1;
			city_edges.pop_front();
		//	printf("city\n");
		}
		
		int u = final.u, v = final.v;
		
		ans += final.w;
		if (!occ[u]) {
			occ[u] = true;
			lasting--;
		}
		if (!occ[v]) {
			occ[v] = true;
			lasting--;
		}
		
		/*
		int u = final.u;
		int v = final.v;
		
		if (find_set(nodes[edge.u]).idx != find_set(nodes[edge.v]).idx) {
			if (country_dis[u][v].first + build_cost < edge.w) {
				printf("选择村路\n");
				edge.w = country_dis[u][v].first + build_cost;// + (1 - c[country_dis[u][v].second].cost) * c[country_dis[u][v].second].cost;
				c[country_dis[u][v].first].built = true;
			}
			ans += edge.w;
			if (!occ[u]) {
				occ[u] = true;
				lasting--;
			}
			if (!occ[v]) {
				occ[v] = true;
				lasting--;
			}
		}
		*/ 
	}
	printf("%d", ans);
	return 0;
} 
