#include <bits/stdc++.h>
using namespace std;
int t, n, a[200005];

int getcu(int u, int clr){
	for(int i = u - 1; i; i --) if((clr >> u - 1 & 1) == (clr >> i - 1 & 1) && a[i] == a[u]) return a[u];
	return 0;
}

void solve1(){
	int ans = 0;
	for(int i = 0; i < (1 << n); i ++){
		int sum = 0;
		for(int j = 1; j <= n; j ++) sum += getcu(j, i);
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		solve1();
	}
	return 0;
}
