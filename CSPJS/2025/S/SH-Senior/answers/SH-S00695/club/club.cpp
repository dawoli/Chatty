#include <iostream>
#include <cstring>
#include <algorithm>
const int MAXN = 1e5+5;
using namespace std;
int a[MAXN][5];
bool occ[MAXN];
struct Club {
	int id;
	int cnt;
} clubs[5];
int ans;
void solve(int& n, int i, int sum) {
	if (i > n) {
		ans = max(sum, ans);
		return;
	}
	for (int j = 1; j <= 3; j++) {
		if (clubs[j].cnt < n / 2) {
			clubs[j].cnt++;
			solve(n, i + 1, sum + a[i][j]);
			clubs[j].cnt--;
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(a, 0, sizeof(a));
		memset(occ, 0, sizeof(occ));
		memset(clubs, 0, sizeof(clubs));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		/*
		sort(clubs + 1, clubs + 3 + 1, cmp);
		printf("受欢迎排序 %d %d %d\n", clubs[1].id, clubs[2].id, clubs[3].id);
		int ans = 0, lasting = n;
		for (int i = 1; i <= 3; i++) {
			int z = 0;
			while (lasting > 0) {
				if (clubs[i].cnt == n / 2) break;
				int idx = 0, curmax = -1;
				for (int j = 1; j <= n; j++) {
					if (!occ[j] && a[j][i] > curmax) {
						curmax = a[j][i];
						idx = j;
					}
				}
				occ[idx] = true;
				clubs[i].cnt++;
				ans += a[idx][i];
				lasting--;
				printf("让%d:%d进入社团%d\n", idx, curmax, i);
			}
		}
		*/
		solve(n, 1, 0);
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
