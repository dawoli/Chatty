// detect

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10; const double LITTLE = 1e-6, EPS = 1e-9;
struct T {
	int d, v, a, L, R, LLIM, RLIM;
	double l, r, llim, rlim;
	bool up;
}gA[N];
struct NEED {
	int l, r;
	
	inline friend bool operator < (const NEED &x, const NEED &y) {
		if (x.r != y.r) return x.r < y.r;
		return x.l < y.l;
	}
}gB[N];
int gLsh[N], gBlk[N], gSum[N], n, m, l, v;
double gLhs[N];

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) {
		cin >> n >> m >> l >> v;
		
		for (register int i = 1; i <= n; i++) {
			int D, V, A;
			cin >> D >> V >> A;
			
			gA[i].d = D, gA[i].v = V, gA[i].a = A;
			if (A < 0) {
				double leave = min(1.0 * l, 1.0 * V * V / (-2 * A)); 
				gA[i].l = D, gA[i].r = D + leave; 
				if (V <= v) gA[i].up = false;
				else { gA[i].up = true;
					double score = 1.0 * (V * V - v * v) / (-2 * A);
					gA[i].llim = D, gA[i].rlim = D + score - LITTLE;
				} 
			} else if (A > 0) {
				gA[i].l = D, gA[i].r = l;
				if (V > v) gA[i].up = true, gA[i].llim = D, gA[i].rlim = l;
				else {
					double score = 1.0 * (v * v - V * V) / (2 * A);
					if (D + score + LITTLE > l) gA[i].up = false;
					else gA[i].up = true, gA[i].llim = D + score + LITTLE, gA[i].rlim = l;
				}
			} else {
				gA[i].l = D, gA[i].r = l;
				if (V <= v) gA[i].up = false;
				else gA[i].up = true, gA[i].llim = D, gA[i].rlim = l;
			}
		}
		
		int cur = 0;
		for (register int i = 1; i <= n; i++)
			gLhs[++cur] = gA[i].l, gLhs[++cur] = gA[i].r, gLhs[++cur] = gA[i].llim, gLhs[++cur] = gA[i].rlim;
		
		for (register int i = 1, x = 0; i <= m; i++)
			cin >> x, gLhs[++cur] = x, gBlk[i] = x; // BUGBUG ∂‡°¡¡À1e6 
		
		for (register int i = 1; i <= cur; i++)
			gLsh[i] = gLhs[i] * 1e6;
		
		sort(gLsh + 1, gLsh + cur + 1);
		int kcur = unique(gLsh + 1, gLsh + cur + 1) - gLsh - 1;
		
//		for (int i = 1; i <= kcur; i++)
//			cout << gLsh[i] << " ";
//		cout << '\n';
		
		for (register int i = 1; i <= n; i++) {
			// cout << gA[i].l << "->" << gA[i].r << "|" << gA[i].llim << "~" << gA[i].rlim << '\n';
			gA[i].L = lower_bound(gLsh + 1, gLsh + kcur + 1, (int)(gA[i].l * 1e6)) - gLsh;
			gA[i].R = lower_bound(gLsh + 1, gLsh + kcur + 1, (int)(gA[i].r * 1e6)) - gLsh;
			gA[i].LLIM = lower_bound(gLsh + 1, gLsh + kcur + 1, (int)(gA[i].llim * 1e6)) - gLsh;
			gA[i].RLIM = lower_bound(gLsh + 1, gLsh + kcur + 1, (int)(gA[i].rlim * 1e6)) - gLsh;
		}
		
		for (register int i = 1; i <= m; i++) 
			gBlk[i] = lower_bound(gLsh + 1, gLsh + kcur + 1, (int)(gBlk[i] * 1e6)) - gLsh;
		
//		for (int i = 1; i <= n; i++)
//			cout << gA[i].llim << "~" << gA[i].rlim << '\n';
//		
//		for (int i = 1; i <= n; i++)
//			cout << gA[i].LLIM << "~" << gA[i].RLIM << '\n';
//		
//		for (int i = 1; i <= m; i++)
//			cout << gBlk[i] << " ";
//		cout << '\n'; 
		
		for (register int i = 1; i <= m; i++)
			gSum[gBlk[i]]++;
		
		for (register int i = 1; i < N; i++)
			gSum[i] += gSum[i - 1];
		
		int ans = 0, cnt = 0;
		for (register int i = 1; i <= n; i++) {
			int sum = gSum[gA[i].RLIM] - gSum[gA[i].LLIM - 1];
			ans += !!sum * gA[i].up;
			
			if (!!sum * gA[i].up) gB[++cnt] = (NEED){gA[i].LLIM, gA[i].RLIM};
			
//			if (gA[i].llim > 844900) cout << "chk:" << i << "->" << gA[i].llim << "~" << gA[i].rlim << '\n';
//			if (!sum) cout << i << ":" << gA[i].llim << "~" << gA[i].rlim << "escape\n";
		} sort(gB + 1, gB + cnt + 1);
		
//		cout << "choose:\n";
//		for (int i = 1; i <= cnt; i++)
//			cout << gB[i].l << "~" << gB[i].r << '\n';
//		cout << '\n';
		
		set<int> se;
		for (register int i = 1; i <= m; i++) se.insert(gBlk[i]);
		
//		cout << "blk:\n";
//		for (int i = 1; i <= m; i++)
//			cout << gBlk[i] << " ";
//		cout << '\n';
		
		if (!cnt) cout << ans << " " << m << '\n'; // BUGBUG ±ﬂΩÁ 
		else {
			auto it = se.upper_bound(gB[1].r); it--; int lft = *it, need = 1; se.erase(it); 
			for (int i = 2; i <= cnt; i++)
				if (lft < gB[i].l) {
					auto it = se.upper_bound(gB[i].r); it--;
					need++, lft = *it; 
				}
			
			cout << ans << " " << m - need << '\n';
		}
		
		memset(gSum, 0, sizeof(gSum));
	}
	
	return 0;
} 
