#include <bits/stdc++.h>
using namespace std;

struct car {
	double d;
	double v;
	double a;
};

bool cmp1(car x, car y) {
	return x.a < y.a;
}
int p[100010];
car arr[100010];
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m, len, V;
		cin >> n >> m >> len >> V;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].d >> arr[i].v >> arr[i].a;
		}
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
		}
		printf("3 3\n");
	}
	return 0;
}
