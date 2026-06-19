#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, mod = 998244353;
int n, m, a[N], x[N];
char c;
int b[N];
bool flag = 1, f[N];
ll ans = 0;
bool check() {
	int cnt = 0, sum = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 0) ++cnt;
	}
	for(int i = 1; i <= n; ++i) {
		if(x[i] > cnt) ++sum;
	}
	return sum >= m;
}
void dfs(int pos) {
	if(pos == n+1) {
		int t = 0;
		for(int i = 1; i <= n; ++i) {
			if(t >= x[b[i]]) ++t;
			if(a[i] == 0) ++t; 
		}
		if(t <= n-m) {
			ans = (ans+1) % mod;
		}
		return ;
	}
	for(int i = 1; i <= n; ++i) {
		if(!f[i]) {
			b[pos] = i;
			f[i] = 1;
			dfs(pos+1);
			f[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> c;
		a[i] = c-'0';
		if(a[i] == 0) flag = 0;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	if(flag || check()) {
		ans = 1;
		for(int i = 2; i <= n; ++i) {
			ans = (ans * i) % mod;
		}
		cout << ans%mod << endl;
		return 0;
	}
	dfs(1);
	cout << ans%mod << endl;
	return 0;
}
