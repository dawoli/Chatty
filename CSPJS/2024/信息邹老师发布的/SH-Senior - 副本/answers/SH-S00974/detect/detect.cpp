#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("detect1.in", "r", stdin);
	//freopen("detect.out", "w", stdout);
	scanf("%d", T);
	while (T--){
		int n, m, L, V, cnt = 0;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		int d[100005], v[100005], a[100005], l[100005], p[100005], vis[100005] = {0};
		for (int i = 1; i <= n; i++){
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
			if (a[i] <= 0){
				if (v[i] <= V) continue;
				vis[i] = 1;
				if (a[i] == 0){
					l[i] = L;
					continue;
				}
				double t = (double)(V - v[i]) / a[i];
				l[i] = (int)d[i] + v[i] * t + 0.5 * a[i] * t * t;
				continue;
			}
			if (v[i] >= V){
				vis[i] = 1;
				l[i] = L;
				continue;
			}
			int s = L - d[i];
			double v1 = (double)sqrt(v[i] * v[i] + 2 * a[i] * s);
			if (v1 <= V) continue;
			vis[i] = 1;
			l[i] = L;
		}
		for (int i = 1; i <= m; i++){
			scanf("%d", &p[i]);
			for (int j = 1; j <= n; j++){
				if (!vis[j] || d[j] > p[i] || vis[j] == -1 || l[j] < p[i]) continue;
				int s = p[i] - d[j];
				double v1 = (double)sqrt(v[j] * v[j] + 2 * a[j] * s);
				if (v1 <= V) continue;
				vis[j] = -1;
				cnt++;
			}
		}
		printf("%d ", cnt);
		
	}
	return 0;
}
