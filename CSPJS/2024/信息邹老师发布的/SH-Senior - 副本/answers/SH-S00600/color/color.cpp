#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
const int M = 2009;
int t, n, a[N], ans, f[M][M];
void dfs(int x,int rnow, int bnow, int s){
//	cout << 1 << endl;
	if(x == n + 1){
		ans = max(ans, s);
		return;
	}
	if(a[x] == a[rnow])dfs(x + 1, x, bnow, s + a[rnow]);
	else	dfs(x + 1, x, bnow, s);
	if(a[x] == a[bnow])dfs(x + 1, rnow, x, s + a[bnow]);
	else    dfs(x + 1, rnow, x, s);
}
void solve_taskone(){
	dfs(1, 0, 0, 0);
}
void solve_tasktwo(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
			f[i][j] = 0;
	int tmp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i - 1; j++){
			tmp = 0;
			if(a[i] == a[i - 1 - j]) tmp = a[i];
			f[i][1] = max(f[i][1], f[i - 1][j] + tmp);
		}
		for(int j = 2; j <= i; j++){
			tmp = 0;
			if(a[i] == a[i - 1]) tmp = a[i - 1];
			f[i][j] = f[i - 1][j - 1] + tmp;
		}
	}
	for(int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(n <= 15){
			solve_taskone();
			cout << ans << endl;
		}
		else{
			if(n <= 2000){
				solve_tasktwo();
				cout << ans << endl;
			}
			else cout << 0 << endl;
		}
	}
	return 0;
}

