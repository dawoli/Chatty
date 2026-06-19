#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-6;
int t, n, m, k, l, v, ans1, ans2, maxn, p[N];
bool f[N];
struct car{
	int d, v, a, id;
	bool flag;
}a[N];
struct node{
	int l, r;
	bool operator< (const node &b) const{
		if (r != b.r)
			return r < b.r;
		return l < b.l;
	}
}b[N];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		memset(f, false, sizeof(f));
		memset(b, 0, sizeof(b));
		ans1 = ans2 = maxn = k = 0;
		scanf("%d%d%d%d", &n, &m, &l, &v);
		for (int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i].d, &a[i].v, &a[i].a);
		}
		for (int i = 1; i <= m; i++){
			scanf("%d", &p[i]);
		}
		for (int i = 1; i <= n; i++){
			if (a[i].a > 0){
				if (v < a[i].v){
					int pos = lower_bound(p + 1, p + m + 1, a[i].d) - p;
					if (pos <= m){
						a[i].flag = true;
						a[i].id = pos;
						ans1++;
						maxn = max(maxn, a[i].id);
					}
				}
				else{
					int pos = upper_bound(p + 1, p + m + 1, a[i].d + (v * v - a[i].v * a[i].v) / (2 * a[i].a)) - p;
					if (pos <= m){
						a[i].flag = true;
						a[i].id = pos;
						ans1++;
						maxn = max(maxn, a[i].id);
					}
				}
			}
			else if (a[i].a == 0){
				if (a[i].v > v && a[i].d <= p[m]){
					a[i].flag = true;
					a[i].id = lower_bound(p + 1, p + m + 1, a[i].d) - p;
					ans1++;
					maxn = max(maxn, a[i].id);
				}
			}
			else{
				if (v < a[i].v && lower_bound(p + 1, p + m + 1, a[i].d) - p <= m){
					int s = a[i].d + (v * v - a[i].v * a[i].v + 2 * a[i].a - 1) / (2 * a[i].a);
					if (s > p[lower_bound(p + 1, p + m + 1, a[i].d) - p]){
						int pos = lower_bound(p + 1, p + m + 1, s) - p - 1;
						a[i].flag = true;
						a[i].id = pos;
						ans1++;
						b[++k] = (node){lower_bound(p + 1, p + m + 1, a[i].d) - p, pos};
//						printf("%d %d\n", b[k].l, b[k].r);
					}
				}
			}
		}
		sort(b + 1, b + k + 1);
		int val = b[1].r;
		if (k){
			ans2++;
		}
		for (int i = 1; i <= k; i++){
			if (val < b[i].l){
				ans2++, val = b[i].r;
			}
		}
		if (n - k && maxn > val){
			ans2++;
		}
		printf("%d %d\n", ans1, m - ans2);
	}
}
