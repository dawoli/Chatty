#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const long long MOD = 998244353;
long long a[MAXN];
long long n;
long long ans = 0;
void dfs(long long num, long long maxnum, long long sum){
	if(num == n + 1){
		if(maxnum * 2 < sum){
			ans++;
			ans %= MOD;
		}
		return;
	}
	dfs(num + 1, max(maxnum, a[num]), sum + a[num]);
	dfs(num + 1, maxnum, sum);
	return;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
