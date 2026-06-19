#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
const int M = 1e6+1;
struct interval {
	int l,r;
	interval (int l=0, int r=0) {l=l; r=r;}
};
int T,n,m,L,V,sum,ans;
int d[N],v[N],a[N],p[N];
bool vis[N];
vector <interval> over;
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		bool fg = 0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if (a[i]) fg = 1;
		}
		if (fg) break;
		for (int i = 1; i <= m; i++) {
			scanf("%d",&p[i]);
			vis[p[i]] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (v[i] > V)
				for (int j = d[i]; j <= n; j++)
					if (vis[j] == 1) {
						ans = m-1;
						over.push_back(interval(d[i],L));
					}
		}
		if (over.size() == 0) ans = m;
		printf("%d %d\n",over.size(),ans);
	}
	return 0;
}
