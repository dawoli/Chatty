#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct car {
	int d; // start point
	int v; // start speed
	int a; // add speed
	car() {}
	car(int _d, int _v, int _a) {
		d = _d;
		v = _v;
		a = _a; 
	}
};

car a[N];
int p[N];
bool f1[N];
vector<int> p2[N];

double calc_v(int v0, int a, int s) {
	return sqrt(1.0 * v0 * v0 + 2.0 * a * s);
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(f1, 0, sizeof(f1));
		for (int i = 0; i < N; ++i) p2[i].clear();
		int n; // #cars
		int m; // #machines
		int L; // length
		int V; // speed limit
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 0; i < n; ++i) {
			int d, v, _a;
			scanf("%d%d%d", &d, &v, &_a);
			a[i] = car(d, v, _a);
		}
		int ans1 = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &p[i]);
			for (int j = 0; j < n; ++j) {
				if (a[j].d > p[i]) continue;
				int v = ceil(calc_v(a[j].v, a[j].a, p[i] - a[j].d));
				if (v > V) {
					if (!f1[j]) {
						ans1++;
						f1[j] = 1;
					}
					p2[i].push_back(j);
				}
			}
		}
		int ans2 = 0;
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < m; ++i) q.push(make_pair(p2[i].size(), i));
		while (q.top().first > 0) {
			pair<int, int> p3 = q.top();
			q.pop();
			if (p3.first != p2[p3.second].size()) continue;
			ans2++;
			for (int i = 0; i < m; ++i) {
				if (i == p3.second) continue;
				bool flg = 0;
				for (int j: p2[p3.second]) {
					vector<int>::iterator idx;
					for (idx = p2[i].begin(); idx != p2[i].end(); ++idx) {
						if (*idx == j) break;
					}
					if (idx != p2[i].end()) {
						flg = 1;
						p2[i].erase(idx, idx + 1);
					}
				}
				if (flg) q.push(make_pair(p2[i].size(), i));
			}
		}
		printf("%d %d\n", ans1, m - ans2);
	}
	return 0;
} 
