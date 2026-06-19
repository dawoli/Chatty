#include <bits/stdc++.h>
using namespace std;
struct Node{
	int l, r;
	bool operator < (Node b){
		if(r == b.r){
			return l < b.l;
		}
		return r < b.r;
	}
};
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, L, V;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		int d[n + 5], v[n + 5], a[n + 5];
		Node car[n + 5];
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
			if(v[i] > V && a[i] >= 0){
				car[i].l = d[i];
				car[i].r = L;
			} else if(v[i] <= V && a[i] <= 0){
				car[i].l = car[i].r = -1;
			} else if(v[i] > V && a[i] < 0){
				car[i].l = d[i];
				car[i].r = min(L, ((V * V - v[i] * v[i] + 1) / (2 * a[i]) + d[i]));
			} else if(v[i] <= V && a[i] > 0){
				car[i].l = min(L, ((V * V - v[i] * v[i]) / (2 * a[i]) + d[i] + 1));
				car[i].r = L;
			}
		}
		sort(car + 1, car + n + 1);
		int p[m + 5];
		for(int i = 1; i <= m; i++){
			scanf("%d", &p[i]);
		}
		int cnt1 = 0, cnt2 = 0;
		bool caught[n + 5];
		for(int i = 1; i <= n; i++){
			caught[i] = false;
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(!caught[j] && p[i] >= car[j].l && p[i] <= car[j].r){
					cnt1++;
					caught[j] = true;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(!caught[i]){
				continue;
			}
			int maxj = 1;
			while(p[maxj] <= car[i].r && maxj <= m){
				maxj++;
			}
			maxj--;
			for(int j = 1; j <= n; j++){
				if(p[maxj] >= car[j].l){
					caught[j] = false;
				}
			}
			cnt2++;
		}
		printf("%d %d\n", cnt1, m - cnt2);
	}
	return 0;
}
