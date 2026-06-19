#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 507, MOD = 998244353;
int n, m;
string s;
int sts[N], c[N];

int f(int n) {
	int ans = 1;
	for(int i=1; i<=n; i++) ans *= i, ans %= MOD;
	return ans;
}

bool used[N];
int pt[N];
int ans;
void dfs(int stp, int lft, int ald) {
	if(lft == 0) { 
//		cout << "YES: " << n - stp + 1 << endl;
		ans += f(n - stp + 1), ans %= MOD; 
		return; 
	} 
//	cout << stp << ' ' << lft << ' ' << ald << endl;
	if(stp == n+1) return;
	for(int i=1; i<=n; i++) {
		if(!used[i]) {
			pt[stp] = i;
			used[i] = 1;
			if(!sts[stp] or ald >= c[i]) dfs(stp+1, lft, ald+1);
			else dfs(stp+1, lft-1, ald);
			used[i] = 0;
		}
	}
}

void bruce() {
	ans = 0;
	dfs(1, m, 0);
	cout << ans;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	cin >> n >> m >> s;
	for(int i=1; i<=n; i++) cin >> c[i];
	sort(c+1, c+1+n);
	for(int i=1; i<=n; i++) sts[i] = s[i-1] - '0';
	bruce();
	return 0;
}


 
