#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100007;
int n;
struct Prf {
	int x, t; 
	bool operator< (Prf other) const { return x < other.x; }
};
Prf d[N][5], cnt[5];
int ans;
int dlt[N];

void test() {
	for(int _=1; _<=3; _++) cnt[_].t = _, cnt[_].x = 0;
	ans = 0;
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int _=1; _<=3; _++) cin >> d[i][_].x, d[i][_].t = _;
		sort(d[i]+1, d[i]+1+3);
		ans += d[i][3].x;
//		cout << d[i][3].t << endl;
		cnt[d[i][3].t].x++; 
	}
	sort(cnt+1, cnt+1+3);
//	cout << cnt[3].x << endl;
	if(cnt[3].x > n/2) {
		int tm = 0;
		for(int i=1; i<=n; i++) 
			if(d[i][3].t == cnt[3].t) dlt[++tm] = d[i][3].x - d[i][2].x;
		sort(dlt+1, dlt+1+tm);
		for(int k=1; k<=tm-n/2; k++) ans -= dlt[k];
	}
	cout << ans << endl;
}

int T;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) test(); 
	return 0;
}


