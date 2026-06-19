#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, a[5005], ans;

void dfs(int step, int sum, int maxa){
	if (step > n){
		if (sum > 2*maxa) ans ++;
		return;
	}
	dfs(step+1, sum+a[step], max(maxa, a[step]));
	dfs(step+1, sum, maxa);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	dfs(1, 0, 0);
	cout << (ans%MOD);
	return 0;
} 
