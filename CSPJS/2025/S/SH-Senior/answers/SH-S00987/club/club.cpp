#include <bits/stdc++.h>
using namespace std;
int a[100005][5], n, ans = -1, step[5];
void dfs(int s, int sum){
	if(s == n){
		ans = max(ans, sum);
	}
	for(int i = 0;i < 3;i++){
		if(step[i] > 0){
			step[i]--;
			dfs(s + 1, sum + a[s][i]);
			step[i]++;
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int x = 20005;
		for(int i = 0;i < n;i++){
			step[i] = n / 2;
			for(int j = 0;j < 3;j++){
				cin >> a[i][j];
			}
		}
		ans = -1;
		dfs(0, 0);
		cout << ans << endl;
	}
	return 0;
}
