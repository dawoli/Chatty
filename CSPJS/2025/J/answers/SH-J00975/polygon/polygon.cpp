#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define int long long
const int maxn = 5005;
const int mod = 998244353;
int n;
int a[maxn], inv[maxn], ji[maxn];
int qpow(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	
	return res;
}
void solvea(){
	ji[0] = 1;
	for(int i = 1; i <= n; i++) ji[i] = ji[i - 1] * i % mod;
	for(int i = 0; i <= n; i++) inv[i] = qpow(ji[i], mod - 2) % mod;
	
	int ans = 0;
	for(int i = 3; i <= n; i++){
		int res = 1;
		
		res = res * ji[n] % mod;
		res = res * inv[n - i] % mod;
		res = res * inv[i] % mod;
		
		ans = (ans + res) % mod;
	}
	
	cout << ans << '\n';
	exit(0);
}
void solvec(){
	int maxx = max(max(a[1], a[2]), a[3]);
	int sum = a[1] + a[2] + a[3];
	
	if(sum > 2 * maxx) cout << "1\n";
	else cout << "0\n";
	
	exit(0);
}
int num = 0;
void dfs(int now, int tot, int maxx, int sum, int lst){
//	printf("now:%lld, tot:%lld, maxx:%lld, sum:%lld\n", now, tot, maxx, sum);
	if(now == tot + 1){
		if(sum > maxx * 2) num = (num + 1) % mod;
		return ;
	}
	
	for(int i = lst + 1; i <= n; i++){
		dfs(now + 1, tot, max(maxx, a[i]), sum + a[i], i);
	}
}
void solveb(){
	for(int i = 3; i <= n; i++){
		dfs(1, i, 0, 0, 0);
//		cout << num << ' ';
	}
	
	cout << num % mod << '\n';
	exit(0);
}
//int dp[maxn][maxn];
//inline void solved(){
//	dp[0][0] = 1;
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= i; j++){
//			
//		}
//	}
//}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	bool flaga = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		
		if(a[i] <= 1) ;
		else flaga = false;
	}
	
	if(n <= 3) solvec();
	
	if(flaga) solvea();
	
	if(n <= 20) solveb();
	
//	solved(); 
	return 0;
}
