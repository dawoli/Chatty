#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200010, M = 1000010;
const LL INF = 1e14;
int n, a[N];
LL f[N], g[M], s[N];

void solve(){
	memset(s, 0, sizeof s);
	memset(f, 0, sizeof f);
	for(int i = 0; i < M; i ++) g[i] = -INF;
	
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	for(int i = 1; i <= n; i ++){
		if(a[i] == a[i - 1]) s[i] = a[i];
	}
	for(int i = 1; i <= n; i ++) s[i] += s[i - 1];
	
	for(int i = 1; i <= n; i ++){
		if(g[a[i]] == -INF) f[i] = s[i - 1];
		else{
			f[i] = g[a[i]] + s[i - 1] + a[i];
		}
		g[a[i]] = max(g[a[i]], f[i] - s[i + 1]);
	}
	LL res = 0;
	for(int i = 1; i <= n; i ++){
		res = max(res, f[i] + s[n] - s[i + 1]);
	}
	cout << res << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	int T;
	cin >> T;

	while(T --){
		cin >> n;
		solve();
	}

	return 0;
}

