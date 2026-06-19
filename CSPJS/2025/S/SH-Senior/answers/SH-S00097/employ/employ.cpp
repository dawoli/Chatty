#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const long long MOD = 998244353;
long long c[MAXN];
long long ans = 1;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(long long i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(long long i = 2; i <= n; i++){
		ans = ans * i % MOD; 
	}
	cout << ans;
	return 0;
}
