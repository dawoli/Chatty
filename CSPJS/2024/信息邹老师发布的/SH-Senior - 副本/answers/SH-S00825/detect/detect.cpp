#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Car{
	int d, v, a;
};

Car car[N];
int mon[N];
int n, m, L, V;

int findmon (int dis) {
	int l = 1, r = m;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (mon[mid] > dis) {
			r = mid - 1;
			ans = r;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &car[i].d, &car[i].v, &car[i].a);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &mon[i]);
		}
		
		int carsum = 0, mondelmax = 0;
		for (int i = 1; i <= n; i++) {
			if (car[i].v <= V) {
				continue;
			} else {
				carsum++;
				int loc = findmon(car[i].d);
				if (car[i].d == mon[loc]) {
					loc--;
				}
				loc++;
				// printf("%d\n", loc);
				mondelmax = max(mondelmax, loc - 1);
			}
		}
		printf("%d %d\n", carsum, mondelmax);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
