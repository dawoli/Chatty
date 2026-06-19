#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, MAXM = 1e5 + 10;
int dList[MAXN], vList[MAXN], aList[MAXN];
int pList[MAXM];
struct Ca {
	int l, r;
	bool operator < (const Ca &c) const {
		if (l == c.l) return r < c.r;
		return l < c.l;
	}
} cList[MAXN];
int main () {
	int T;
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 0; t < T; t ++) {
		int n, m, L, V;
		scanf("%d %d %d %d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i ++) scanf("%d %d %d", &dList[i], &vList[i], &aList[i]);
		for (int i = 1; i <= m; i ++) scanf("%d", &pList[i]);
		int ans1 = 0;
		for (int i = 1; i <= n; i ++) {
			if (dList[i] > pList[m]) continue;
			if (vList[i] > V) {
				if (aList[i] >= 0) {
					ans1 ++;
					cList[ans1].l = lower_bound(pList + 1, pList + m + 1, dList[i]) - pList;
					cList[ans1].r = m;
				}
				else {
					int overX_2a = V * V - vList[i] * vList[i];
					int* nearP = lower_bound(pList + 1, pList + m + 1, dList[i]);
					if (2 * aList[i] * (*nearP - dList[i]) > overX_2a) {
						ans1 ++;
						cList[ans1].l = nearP - pList;
						cList[ans1].r = lower_bound(pList + 1, pList + m + 1, dList[i] + 0.5 * (double)overX_2a / aList[i]) - pList - 1;
					}
				}
			}
			else {
				if (aList[i] > 0) {
					int overX_2a = V * V - vList[i] * vList[i];
					int farX = pList[m] - dList[i];
					if (2 * aList[i] * farX > overX_2a) {
						ans1 ++;
						cList[ans1].l = upper_bound(pList + 1, pList + m + 1, dList[i] + 0.5 * (double)overX_2a / aList[i]) - pList;
						cList[ans1].r = m;
					}
				}
			}
		}
		printf("%d ", ans1);
		if (ans1 == 0) {
			printf("%d\n", m);
			continue;
		}
		sort(cList + 1, cList + ans1 + 1);
		int ans2 = 1, lastL = cList[1].l, lastR = cList[1].r;
		for (int i = 2; i <= ans1; i ++) {
			if (cList[i].l > lastR) {
				ans2 ++;
				lastL = cList[i].l;
				lastR = cList[i].r; 
			}
			else if (cList[i].l > lastL) {
				lastL = cList[i].l;
				if (cList[i].r < lastR) {
					lastR = cList[i].r;
				}
			}
		}
		printf("%d\n", m - ans2);
	}
	return 0;
}
