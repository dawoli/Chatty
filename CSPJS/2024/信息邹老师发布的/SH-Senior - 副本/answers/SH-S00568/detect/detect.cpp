#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

int T;

struct node {
	int d, v, a;
	bool cat;
}car[100005];

struct fs {
	int fz, fm;
}arr[100005];

struct jk {
	int l, use;
}p[100005];

inline int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n, m, L, V;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		bool A = 1, B = 1, C = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &car[i].d, &car[i].v, &car[i].a);
			if (car[i].a == 0 && A)
				A = 1;
			else if (car[i].a > 0 && B) {
				B = 1, A = 0, C = 0;
			}
			else if (car[i].a < 0 && C) {
				C = 1;
				A = 0, B = 0;
			}
			car[i].cat = 0;
		}
		for (int i = 1; i <= m; i++) 
			scanf("%d", &p[i].l), p[i].use = 0;
		if (A) {
			for (int i = 1; i <= n; i++) {
				if (car[i].v > V) {
					for (int j = m; j >= 1; j--) {
						if (p[j].l >= car[i].d && p[j].use) {
							car[i].cat = 1;
							break;
						}
					}
					if (car[i].cat == 0) {
						for (int j = m; j >= 1; j--) {
							if (p[j].l >= car[i].d) {
								p[j].use = 1;
								car[i].cat = 1;
								break;
							}
						}
					}
				}
			}	
		}
		for (int i = 1; i <= n; i++) {
			arr[i].fz = V * V - car[i].v * car[i].v;
			arr[i].fm = 2 * car[i].a;
			int t = gcd(arr[i].fz, arr[i].fm);
			arr[i].fz /= t, arr[i].fm /= t;
			if (arr[i].fz < 0) arr[i].fz = -arr[i].fz, arr[i].fm = -arr[i].fm;
		}
		if (B) {
			for (int i = 1; i <= n; i++) {
				int ti = car[i].v * (V - car[i].v) / car[i].a;
				if (car[i].v > V) {
					for (int j = m; j >= 1; j--) {
						if (p[j].l >= car[i].d && p[j].use) {
							car[i].cat = 1;
							break;
						}
					}
					if (car[i].cat == 0) {
						for (int j = m; j >= 1; j--) {
							if (p[j].l >= car[i].d) {
								p[j].use = 1;
								car[i].cat = 1;
								break;
							}
						}
					}
				}
				else if (car[i].v <= V) {
					int t = car[i].d + arr[i].fz / arr[i].fm;
					for (int j = m; j >= 1; j--) {
						if (p[j].l > t && p[j].use) {
							car[i].cat = 1;
							break;
						}
					}
					if (car[i].cat == 0) {
						for (int j = m; j >= 1; j--) {
							if (p[j].l > t) {
								p[j].use = 1;
								car[i].cat = 1;
								break;
							}
						}
					}
				}
			}
		}
		else if (C) {
			for (int i = 1; i <= n; i++) {
				if (car[i].v > V) {
					int t = car[i].d + arr[i].fz / arr[i].fm;
					for (int j = m; j >= 1; j--) {
						if (p[j].l <= t && p[j].l >= car[i].d && p[j].use) {
							car[i].cat = 1;
							break;
						}
					}
					if (car[i].cat == 0) {
						for (int j = 1; j <= m; j++) {
							if (p[j].l <= t && p[j].l >= car[i].d) {
								car[i].cat = 1;
								p[j].use = 1;
								break;
							}
						}
					}
				}
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++)
			if (car[i].cat) ans1++;
		for (int i = 1; i <= m; i++)
			if (!p[i].use) ans2++;
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
