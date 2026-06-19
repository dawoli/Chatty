#include <bits/stdc++.h>
const double acc = 0.001;

int n, m, l, V;

using namespace std;

struct Car {
	int d, v0, a;
	double chunkl, chunkr;
} car[114514];
int p[114514];

bool cmp(Car a, Car b) {
	return a.chunkr < b.chunkr;
}

void solve0() {
	int cnt = 0;
	
	int lstd = p[m-1];
	
	for (int i = 0; i < n; i++) {
		if (car[i].v0 > V && car[i].d <= lstd) cnt++;
	}
	
	cout << cnt << ' ' << m - 1 << endl;
}

void dfs() {
	
}

void solve() {
	cin >> n >> m >> l >> V;
	
	int type = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> car[i].d >> car[i].v0 >> car[i].a;
		if (car[i].a > 0) {
			car[i].chunkl = car[i].d + (V * V - car[i].v0 * car[i].v0) / (2 * car[i].a) + 2 * acc;
			car[i].chunkr = l;
			type = 1;
		} else if (car[i].a < 0) {
			car[i].chunkr = car[i].d + (V * V - car[i].v0 * car[i].v0) / (2 * car[i].a) - 2 * acc;
			car[i].chunkl = car[i].d;
			type = 2;
		} else if (car[i].a == 0) {
			if (car[i].v0 > V) {
				car[i].chunkl = car[i].d;
				car[i].chunkr = l;
			} else if (car[i].v0 <= V) {
				car[i].chunkl = l + 1;
				car[i].chunkr = -1;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	
		
	sort(car, car + n, cmp);
	sort(p, p + m);
	
	if (type == 0) {
		solve0();
		return;
	}

	dfs();
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		solve();
	}
}
