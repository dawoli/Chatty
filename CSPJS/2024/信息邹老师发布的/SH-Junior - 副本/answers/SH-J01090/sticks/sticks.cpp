#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
int n=0;
ll ans = 0;

int dig_to_line(int x) {
	if (x == 0) return 6;
	if (x == 1) return 2;
	if (x == 2) return 5;
	if (x == 3) return 5;
	if (x == 4) return 4;
	if (x == 5) return 5;
	if (x == 6) return 6;
	if (x == 7) return 3;
	if (x == 8) return 7;
	if (x == 9) return 6;
}

void dfs(int nowsum=0, ll nownum=0, bool allow_zero=false) {
	if (nowsum == n) {
		ans = min(ans, nownum);
		return;
	}
	if (nownum >= 1ll<<60) {
		// NO solution
		return;
	}
	for (int i=0;i<=9;i++) {
		if (i == 0 && !allow_zero) continue;
		ll nownum1 = nownum * 10ll + i;
		if (nowsum + dig_to_line(i) > n) continue;
		dfs(nowsum+dig_to_line(i), nownum1, true);
	}
}

void solve() {
	// 1<=T<50, 1<=N<=100000
	// 10%: N <= 20 
	// 30%: N = 7k && N >= 100
	// 30%: N = 7k+1 && N >= 100
	scanf("%d", &n);
	ans = 1LL << 60;
	if (n <= 20) {
		dfs(0, 0, false);
		if (ans == (1LL<<60)) {
			printf("-1\n");
		} else {
			printf("%lld\n", ans);
		}
	} else if (n % 7 == 0) {
		int cnt = n/7;
		for (int i=1;i<=cnt;i++) {
			printf("8"); 
		}
		printf("\n"); 
	} else if (n % 7 == 1) {
		printf("16"); 
		int cnt = n/7-1;
		for (int i=1;i<=cnt;i++) {
			printf("8"); 
		}
		printf("\n"); 
	} else {
		printf("-1\n");
	}
	
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
	
	return 0;
} 
