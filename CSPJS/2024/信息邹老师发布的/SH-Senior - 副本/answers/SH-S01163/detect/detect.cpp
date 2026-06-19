#include <bits/stdc++.h>
using namespace std;
#define int long long
#define C 100020
int T;
int n, m, L, V;
int p[C];
struct Car{
	int d, v, a;
} car[C];

int ans1, ans2;
bool bye[C], OverRide[C], flag[C];
vector<int> sss[C];

void _() {
	ans1 = 0, ans2 = 0;
	memset(OverRide, false, sizeof OverRide);
	memset(bye, true, sizeof bye);
	for(int i = 1; i <= n; i++)
		sss[i].clear();

	cin >> n >> m >> L >> V;
	for(int i = 1; i <= n; i++)
		cin >> car[i].d >> car[i].v >> car[i].a;
	for(int i = 1; i <= m; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++) {
		if(car[i].a > 0) {
			double t_sOR = 1. * (V - car[i].v) / car[i].a;
			double d_sOR = car[i].d + t_sOR * car[i].v + 0.5 * t_sOR * t_sOR * car[i].a; 
			for(int j = 1; j <= m; j++){
				if(p[j] > d_sOR) {
					OverRide[i] = true;
					sss[i].push_back(p[j]);
				}
			}
		} else if(car[i].a == 0) {
			for(int j = 1; j <= m; j++)
				if(car[i].v > V && p[j] >= car[i].d) {
					OverRide[i] = true;
					sss[i].push_back(p[j]);
				}
		} else {
			if(car[i].v <= V) continue;
			double t_eOR = 1. * (V - car[i].v) / car[i].a;
			double d_eOR = car[i].d + t_eOR * car[i].v + 0.5 * t_eOR * t_eOR * car[i].a;
			for(int j = 1; j <= m; j++)
				if(p[j] < d_eOR && p[j] >= car[i].d) {
					OverRide[i] = true;
					sss[i].push_back(p[j]);
				}
		}
	}
	for(int i = 1; i <= n; i++)
		if(OverRide[i]) ans1++;
	cout << ans1 << " ";

	ans2 = 2e9;
	for(int S = 0; S < (1 << m); S++) {
		memset(flag, false, sizeof flag);
		for(int i = 1; i <= m; i++) {
			if((S >> i - 1) & 1)
				for(int j = 1; j <= n; j++)
					if(sss[j].size() != 0)
						for(auto k : sss[j])
							if(k == p[i]){
								flag[j] = true;
								break;
							}
		}
		bool t = true;
		for(int i = 1; i <= n; i++)
			if(sss[i].size() != 0)
				t &= flag[i];
		if(t) ans2 = min(ans2, 1ll * __builtin_popcount(S));
	}
	cout << m - ans2 << endl;
}

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	for(cin >> T; T--; _());
	return 0;
}