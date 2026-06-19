#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long MOD = 998244353;

long long n;
long long a[5802];
long long cnt = 0;

bool vis[5802];

void dfs(int ind){
	if(ind == n + 1){
		long long s = 0, maxn = 0;
		for(int i = 1; i <= n; i ++)if(vis[i]){
			s += a[i];
			maxn = max(maxn, a[i]);
		}
		if((s - maxn) > maxn)cnt ++;
		return ;
	}
	
	dfs(ind + 1);
	vis[ind] = 1;
	dfs(ind + 1);
	vis[ind] = 0;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1; i <= n; i ++)cin >> a[i];
	
	bool f = 0;
	for(int i = 1; i <= n; i ++){
		if(a[i] != 1)f = 1;
	}
	if(!f){
		long long ans = 1;
		for(int i = 1; i <= n; i ++){
			ans = (ans * 2) % MOD;
		}
		ans = ans - 1 - n - n * (n - 1) / 2;
		if(ans < 0)ans += MOD;
		ans = ans % MOD;
		cout << ans << endl;
		return 0;
	}
	dfs(1);
	cout << cnt << endl;
	return 0;
}
