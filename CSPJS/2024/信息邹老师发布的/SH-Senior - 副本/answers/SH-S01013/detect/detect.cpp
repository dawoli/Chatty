#include <bits/stdc++.h>
using namespace std;
long long T, n, m, L, V, d[100010], a[100010], v[100010], p[100010], t[1000010], s2[1000010];



int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	
	while(T--) {
		memset(d, 0, sizeof d);
		memset(a, 0, sizeof a);
		memset(v, 0, sizeof v);
		memset(p, 0, sizeof p);
		memset(t, 0, sizeof t);
		memset(s2, 0, sizeof s2);
		cin >> n >> m >> L >> V;
		bool fa = true, fb = true, fc = true;
		for(int i=1;i<=n;i++) {
			scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
			if(a[i] != 0) {
				fa = false;
			}
			if(a[i] < 0) fb=0;
			if(a[i] > 0) fc=0;
		}
		long long maxp = -1;
		for(int i=1;i<=m;i++) {
			scanf("%lld", &p[i]);
			t[p[i]] = i;
			maxp = max(maxp, p[i]);
		}
		int j = 1;
		for(int i=1;i<=L;i++) {
			if(p[j] >= i) s2[i] = p[j];
			else {
				j++;
				s2[i] = p[j];
			} 
		} 
		long long ans1 = 0, ans2 = 0;
		if(fa == true) {
			for(int i=1;i<=n;i++) {
				if(d[i]<=maxp && v[i]>V) ans1++;
			}
			ans2 = m-1;
			if(ans1 == 0) ans2++;
		}	
		else if(fb == true) {
			for(int i=1;i<=n;i++) {
				if(v[i]>V) {
					if(d[i]<=maxp) ans1++;
				}
				else if(d[i]*2*a[i]+V*V-v[i]*v[i]<maxp*2*a[i]) ans1++;
			}
			ans2 = m-1;
		}
		else if(fc == true) {
			long long minn = 1e18;
			for(int i=1;i<=n;i++) {
				if(v[i]<V) {
					minn = min(minn, s2[d[i]]);
					continue;
				}
				double ci = 1.0*(1.0*V*V-1.0*v[i]*v[i])/(2.0*a[i])+1.0*d[i];
				if(s2[d[i]] < ci) ans1++;
				int tu = s2[(long long)ceil(ci)];
				minn = min(minn, s2[d[i]]);
			}
			ans2 = t[minn];
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
} 
/*
20 points now
*/
