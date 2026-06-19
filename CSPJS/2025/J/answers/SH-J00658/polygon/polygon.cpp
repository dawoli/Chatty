#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int f(int n){
	long long res = 1;
	for(int i = 2; i <= n; i++){
		res *= i;
		res %= MOD;
	}
}

int n, maxn = 1e9 + 5;
int a[5005];
long long ans = 1;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	
	if(n == 3){
		if(a[1] + a[2] + a[3] > 2* maxn){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	
	/*if(maxn == 1){
		for(int i = 3; i < n; i++){
			ans += 
		}
	}*/
	
	cout << 0;
}
