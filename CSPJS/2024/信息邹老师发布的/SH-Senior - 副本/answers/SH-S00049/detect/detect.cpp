#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[3010], v[3010], a[3010];
int p[3010];
set<int>s[3010];
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%lld", &t);
	//int ccccc = 0;
	while(t--) {
		int n, m, L, V;
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
		}
		for(int i = 1; i <= m; i++) {
			scanf("%lld", &p[i]);
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			bool flag = 0;
			for(int j = 1; j <= m; j++) {
				if(d[i] > p[j]) {
					continue;
				}
				double spe = sqrt(v[i] * v[i] + 2 * a[i] * (p[j] - d[i]));
				if(spe > V) {
					//printf("%lld %lld %lf\n", i, j, spe);
					flag = 1;
					s[j].insert(i);
				}
			}
			if(flag == 1) {
				cnt++;
			}
		}
		int ccnt = 0;
		while(1) {
			/*
			for(int i = 1; i <= m; i++) {
				printf("%lld\n", i);
				auto it = s[i].begin();
				for(; it != s[i].end(); it++) {
					int now = *it;
					printf("%lld ", now);
				}
				printf("\n\n");
			}
			*/
			int maxx = -1e18, maxn;
			for(int i = 1; i <= m; i++) {
				int siz = s[i].size();
				if(siz > maxx) {
					maxx = siz;
					maxn = i;
				}
			}
			if(maxx == 0) {
				break;
			}
			ccnt++;
			auto it = s[maxn].begin();
			for(; it != s[maxn].end(); it++) {
				for(int j = 1; j <= m; j++) {
					if(j == maxn) {
						continue;
					}
					int now = *it;
					s[j].erase(now);
					//ccccc++;
				}
			}
			while(s[maxn].size()) {
				it = s[maxn].begin();
				s[maxn].erase(it);
			}
		}
		printf("%lld %lld\n", cnt, m - ccnt);
		for(int i = 1; i <= m; i++) {
			while(s[i].size()) {
				auto it = s[i].begin();
				s[i].erase(it);
			}
		}
	}
}
