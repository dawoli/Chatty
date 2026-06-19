#include<bits/stdc++.h>
using namespace std;
long long t, n, m, L, V, sp[100010], ans1, ans2;
struct kill{
	long long l, r, ps;
	bool ab = 0;
	bool operator< (const kill &t)const{
		return r < t.r || (r == t.r) && (l > t.l);
	}
};
kill kl[100010];
void solve(){
	scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
	ans1 = ans2 = 0;
	long long idx = 0;
	for(int i = 1; i <= n; i++){
		long long d, v, a;
		scanf("%lld%lld%lld", &d, &v, &a);
		if(a == 0){
			if(v > V){
				kl[++idx].l = d;
				kl[idx].r = L;
				kl[idx].ps = 0;
				kl[idx].ab = 0;
			}
		}
		else if(a > 0){
			if(v > V){
				kl[++idx].l = d;
				kl[idx].r = L;
				kl[idx].ps = 0;
				kl[idx].ab = 0;
			}
			else{
				long long x = V * V - v * v, y = 2 * a;
				long long dis = x / y + 1;
				if(d + dis <= L){
					kl[++idx].l = d + dis;
					kl[idx].r = L;
					kl[idx].ps = 0;
					kl[idx].ab = 0;
				} 
			}
		}
		else{
			if(v > V){
				long long x = v * v - V * V, y = 2 * (-a);
				long long dis = x / y - bool(x % y == 0);
				kl[++idx].l = d;
				kl[idx].r = min(d + dis, L);
				kl[idx].ps = 0;
				kl[idx].ab = 0;
			}
		}
	}
	n = idx;
	sort(kl + 1, kl + n + 1);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &sp[i]);
	}
	for(int i = m, j = n; i >= 1 && j >= 1; i--){
		while(j >= 1 && kl[j].r >= sp[i]){
			kl[j].ps = i;
			j--;
		}
	}
	sp[0] = -1;
	for(int i = 1; i <= n; i++){
		if(kl[i].l <= sp[kl[i].ps]){
			ans1++;
			kl[i].ab = 1;
		}
	}
	long long ls = -1;
	ans2 = m;
	for(int i = 1; i <= n; i++){
		if(kl[i].ab == 0){
			continue;
		}
		if(ls < kl[i].l){
			ls = sp[kl[i].ps];
			ans2--;
		}
	}
	printf("%lld %lld\n", ans1, ans2);
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
