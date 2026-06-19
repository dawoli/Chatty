#include <bits/stdc++.h>
using namespace std;
int T,n,a[210][5],mark[210],ans = 0;
void dfs(int i,int j,int k,int sum){
	if (i == n + 1){
		ans = max(sum,ans);
		return;
	}
	if (j + 1 <= n / 2) dfs(i+1,j+1,k,sum + a[i][0]);
	if (k + 1 <= n / 2) dfs(i+1,j,k+1,sum + a[i][1]);
	if (i - j - k <= n / 2) dfs(i+1,j,k,sum + a[i][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--){
		ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++){
			for (int j = 0;j < 3;j++) cin >> a[i][j];
		}
		dfs(1,0,0,0);
		cout << ans << endl;
	}
}
