//detect
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXL = 1e6 + 5, MAXN = 1e5 + 5;
ll t, n, m, L, V, d[MAXN], v[MAXN], a[MAXN], p[MAXN], l[MAXN], r[MAXN];
bool chao[MAXN];

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
    bool flgA, flgB;
    scanf("%lld", &t);
	while (t--){
		flgA = 1;
		flgB = 1;
	    scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
	    for (ll i = 1; i <= n; i++){
	    	scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
	    	if (a[i] != 0) 
			    flgA = 0; 
			if (a[i] <= 0)
			    flgB = 0; 
		}
		for (ll i = 1; i <= m; i++){
			scanf("%lld", &p[i]);
		}
		if (flgA){
			ll ans1 = 0, ans2;
			for (ll i = 1; i <= n; i++){
				if (v[i] > V){
					if (d[i] <= p[m]) 
					    ans1++;
				}
			}
			ans2 = m-(ans1>0);
			printf("%lld %lld\n", ans1, ans2);
		} else if (n <= 30){
			double s;
			ll ans1 = 0, ans2 = 0;
			for (ll i = 1; i <= n; i++){
				if (a[i] == 0){
					if (v[i] > V){
					    chao[i] = 1;
					    l[i] = m+1;
					    for (ll j = 1; j <= m; j++){
					    	if (p[j] >= d[i]){
					    		l[i] = j;
					    		break;
							}
						}
						r[i] = m;
						if (l[i] > r[i]){
							chao[i] = 0; 
						}
					} else{
						chao[i] = 0;
					}
					continue;
				}
				s = (double)(V*V-v[i]*v[i])/2.0/a[i];
				if (s <= 0){
					if (v[i] > V){
						chao[i] = 1;
					    l[i] = m+1;
					    for (ll j = 1; j <= m; j++){
					    	if (p[j] >= d[i]){
					    		l[i] = j;
					    		break;
							}
						}
						r[i] = m;
						if (l[i] > r[i]){
							chao[i] = 0; 
						}
					} else{
						chao[i] = 0;
					}
					continue;
				}
				chao[i] = 1;
				if (v[i] > V){
					l[i] = d[i];
					r[i] = min((ll)(d[i]+floor(s)), L);
				} else{
					l[i] = (ll)(d[i]+ceil(s));
					if (l[i] > L){
						chao[i] = 0;
						continue;
					}
					r[i] = L;
				}
				bool f1 = 0, f2 = 0;
				for (ll j = 1; j <= m; j++){
					if (p[j] >= l[i]){
						l[i] = j;
						f1 = 1;
						break;
					}
				}
				for (ll j = m; j >= 1; j--){
					if (p[j] <= r[i]){
						r[i] = j;
						f2 = 1;
						break;
					}
				}
				if (l[i]>r[i] || (!f1) || (!f2))
					chao[i] = 0;
			}
			bool flgi, flgj;
			ll cnt1;
			for (ll i = 0; i < (1<<m); i++){
				flgi = 1;
				for (ll j = 1; j <= n; j++){
					if (!chao[j]) continue;
					flgj = 0;
					for (ll k = l[j]-1; k <= r[j]-1; k++){
						if ((i>>k)&1){
							flgj = 1;
							break;
						}
					} 
					if (!flgj){
						flgi = 0;
						break;
					}
				}
				if (!flgi)
					continue;
				cnt1 = 0;
				for (ll k = 0; k < m; k++)
					cnt1 += ((i>>k)&1);
				ans2 = max(ans2, m-cnt1);
			}
			ans1 = 0;
			for (ll i = 1; i <= n; i++)
				ans1 += chao[i];
			printf("%lld %lld\n", ans1, ans2);
		} else{
			double s;
			for (ll i = 1; i <= n; i++){
				if (a[i] == 0){
					if (v[i] > V){
					    chao[i] = 1;
					    l[i] = m+1;
					    for (ll j = 1; j <= m; j++){
					    	if (p[j] >= d[i]){
					    		l[i] = j;
					    		break;
							}
						}
						r[i] = m;
						if (l[i] > r[i]){
							chao[i] = 0; 
						}
					} else{
						chao[i] = 0;
					}
					continue;
				}
				s = (double)(V*V-v[i]*v[i])/2.0/a[i];
				if (s <= 0){
					if (v[i] > V){
						chao[i] = 1;
					    l[i] = m+1;
					    for (ll j = 1; j <= m; j++){
					    	if (p[j] >= d[i]){
					    		l[i] = j;
					    		break;
							}
						}
						r[i] = m;
						if (l[i] > r[i]){
							chao[i] = 0; 
						}
					} else{
						chao[i] = 0;
					}
					continue;
				}
				chao[i] = 1;
				if (v[i] > V){
					l[i] = d[i];
					r[i] = min((ll)(d[i]+floor(s)), L);
				} else{
					l[i] = (ll)(d[i]+ceil(s));
					if (l[i] > L){
						chao[i] = 0;
						continue;
					}
					r[i] = L;
				}
				bool f1 = 0, f2 = 0;
				for (ll j = 1; j <= m; j++){
					if (p[j] >= l[i]){
						l[i] = j;
						f1 = 1;
						break;
					}
				}
				for (ll j = m; j >= 1; j--){
					if (p[j] <= r[i]){
						r[i] = j;
						f2 = 1;
						break;
					}
				}
				if (l[i]>r[i] || (!f1) || (!f2))
					chao[i] = 0;
			}
			ll ans1 = 0, ans2 = 0;
			for (ll i = 1; i <= n; i++){
				ans1 += chao[i];
			}
			ans2 = m-(ans1>0);
			printf("%lld %lld\n", ans1, ans2);
		} 
	} 
	return 0;
} 

