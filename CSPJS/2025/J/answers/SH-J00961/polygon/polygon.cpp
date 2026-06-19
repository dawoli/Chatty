#include <bits/stdc++.h>
using namespace std;
int n, a[5009], maxn;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	long long ans = 0;
	if(n < 3) cout << 0 << endl;
	else if(n == 3){
		if(a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3]))) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if(maxn == 1){
		long long tmp = (n * (n - 1) * (n - 2) / 6) % 998244353;
		ans = (ans + tmp) % 998244353;
		int sum = 3;
		while(sum <= n){
			tmp = (tmp * (n - sum) / (sum + 1)) % 998244353;
			ans = (ans + tmp) % 998244353;
			sum++;
		}
		cout << ans << endl;
	}
	return 0;
}
