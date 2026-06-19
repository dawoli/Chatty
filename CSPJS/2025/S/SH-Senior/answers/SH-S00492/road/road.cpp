#include<bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n, m, k, fa[10020], c[15], a[15][10010], idx, ans[1050], fl, oc[1050], tt[1050];
struct ird{
	long long u, v, w;
	bool operator< (const ird &t)const{
		return w < t.w;
	}
};
long long find(long long p){
	if(fa[p] != p){
		fa[p] = find(fa[p]);
	}
	return fa[p];
}
long long lb(long long i){
	return i & -i;
}
ird nr[1000010], tmp[110020], ar[15][10010], dp[1050][10010];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%lld%lld%lld", &nr[i].u, &nr[i].v, &nr[i].w);
	}
	for(int i = 1; i <= k; i++){
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%lld", &a[i][j]);
			ar[i][j] = {n + i, j, a[i][j]};
		}
		ar[i][n + 1] = {0, 0, inf};
		sort(ar[i] + 1, ar[i] + n + 1);
	}
	sort(nr + 1, nr + m);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	idx = 0;
	for(int i = 1; i <= m; i++){
		long long u = nr[i].u, v = nr[i].v, w = nr[i].w;
		if(find(u) != find(v)){
			ans[0] += w;
			fa[find(v)] = find(u); 
			idx++;
			dp[0][idx] = nr[i];
		}
//		printf("%lld %lld %lld\n", u, v, w); 
	}
	dp[0][idx + 1] = {0, 0, inf};
	fl = (1 << k) - 1;
	for(int sta = 1; sta <= fl; sta++){
		long long tmp = sta;
		while(tmp > 0){
			tmp -= lb(tmp);
			oc[sta]++;
		}
	}
	for(int i = 1; i <= 10; i++){
		tt[1 << (i - 1)] = i;
	}
	for(int cnt = 1; cnt <= k; cnt++){
		for(int sta = 1; sta <= fl; sta++){
			if(oc[sta] != cnt){
				continue;
			}
//			printf("%lld\n", sta);
			for(int i = 1; i <= n + k; i++){
				fa[i] = i;
			}
			long long p1 = 0, p2 = 0, us = sta - lb(sta), ad = tt[lb(sta)];
			long long tmp = sta;
			while(tmp > 0){
				ans[sta] += c[tt[lb(tmp)]];
				tmp -= lb(tmp);
			}
//			printf("%lld %lld\n", us, ad);
			idx = 0;
			while(dp[us][p1 + 1].w != inf || ar[ad][p2 + 1].w != inf){
				ird cur;
				if(dp[us][p1 + 1].w <= ar[ad][p2 + 1].w){
					cur = dp[us][p1 + 1];
					p1++;
				}
				else{
					cur = ar[ad][p2 + 1];
					p2++;
				}
//				printf("%lld %lld\n", p1, p2);
				long long u = cur.u, v = cur.v, w = cur.w;
				if(find(u) != find(v)){
//					printf("%lld %lld %lld\n", u, v, w);
					ans[sta] += w;
					fa[find(v)] = find(u); 
					idx++;
					dp[sta][idx] = cur;
				}
				dp[sta][idx + 1] = {0, 0, inf};
			}
//			printf("%lld %lld\n", idx, cnt + n - 1);
			ans[0] = min(ans[0], ans[sta]);
		}
	}
	printf("%lld\n", ans[0]);
	return 0;
} 
