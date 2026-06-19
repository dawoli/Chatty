#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	long long ans = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
	}
	for(int i = 1; i <= n; i++){
		ans = ans * i % 998244353;
	}
	cout << ans;
	return 0;
}
