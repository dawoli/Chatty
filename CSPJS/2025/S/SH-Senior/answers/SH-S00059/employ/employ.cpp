#include<bits/stdc++.h>
using namespace std;
#define N 510
int c[N], a[N], vis[N];
string s;
int n, m;
long long ans = 0;
bool check() {
	int cnt = 0, tot = 0;
	for(int i = 1; i <= n; i++) {
		if(cnt >= c[a[i]]) {
			cnt++;
			continue;
		}
		if(s[i] == '1') {
			tot++;
		}
		else {
			cnt++;
		}
	}
	if(tot >= m) return 1;
	else return 0;
}
void dfs(int dep) {
	if(dep == n + 1) {
		if(check()) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		a[dep] = i;
		dfs(dep + 1);
		a[dep] = 0;
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	s = '#' + s;
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	dfs(1);
	printf("%lld", ans);
}
