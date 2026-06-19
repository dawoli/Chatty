#include <bits/stdc++.h> 


using namespace std;
using ll = long long;
int n, m, c[500010], permu[500010];
char s[100010];

void solve() {
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i=1;i<=n;i++) scanf("%d", &c[i]), permu[i]=i;
	ll ways = 0;
	if (n<=10) {
		// Test 1,2 (8pts): n<=10
		// O(n!)
		
		do {
			int res = 0;
			int failed = 0;
			for (int i=1;i<=n;i++) {
				if (s[i-1] == '0' || failed >= c[permu[i]]) ++failed;
				else ++res;
			}
			if (res >= m) ways = (ways + 1) % 998244353;
		} while (next_permutation(permu+1, permu+n+1));
		printf("%lld\n", ways);
		return;
	} else if (m==n) {
		// Test 15 (4pts): n==m
		// 有n!个解当且仅当s全是1且所有c[i] != 0
		// 否则无解
		for (int i=1;i<=n;i++) {
			if (c[i]==0 || s[i-1]=='0') {
				puts("0");
				return;
			} 
		}
		ways = 1;
		for (int i=1;i<=n;i++) 
			ways = (ways * i) % 998244353;
		printf("%lld\n", ways);
		return;
	}
	int ccc = 0, ddd = 0;
	for (int i=1;i<=n;i++) {
		ccc += (c[i] != 0);
		ddd += (s[i-1] == '1'); 
	}
	if (ccc < m || ddd < m) puts("0");
	else puts("0");
}


int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int T = 1;
	// scanf("%d", &T);
	while (T--) solve();
	return 0;
}
