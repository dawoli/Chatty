#include<bits/stdc++.h>
using namespace std;
int n, a[5005], b[2005], vis[2005];
int ans;
void dfs(int x, int sum, int maxa, int c){
	//cout << x << " " << sum << " " << maxa << " " << c << endl;
	if(x == n + 1){
		if(sum > 2 * maxa){
			ans++;
			//cout << sum << " " << maxa << endl;
		} 
	}
	else{
		if(vis[x] == 0){
			vis[x] = 1;
			dfs(x + 1, sum + a[x], max(maxa, a[x]), c++);
			vis[x] = 0;
		}
		dfs(x + 1, sum, maxa, c);
	}
	return;
} 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n == 3) {
		if(a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3]))) {
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}
