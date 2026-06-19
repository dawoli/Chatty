#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[210],c[210][210],f[210][210][2];
int ib[210],lst[2];
void dfs(int x){
	if(x > n){
		int cnt = 0;
		lst[0] = lst[1] = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == a[lst[ib[i]]]) cnt += a[i];
			lst[ib[i]] = i;
		}
		ans = max(ans,cnt);
		return ;
	}
	dfs(x + 1);
	ib[x] = 1;
	dfs(x + 1);
	ib[x] = 0;
}				
void solve(){
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++) c[i][j] = c[i][j - 1] + (a[j - 1] == a[j]?a[j]:0);
	}
	for(int i = 2;i <= n;i++){
		for(int j = 1;j < i;j++){
			f[i][j][0] = f[i][j][1] = 0;
			for(int k = 0;k < j;k++){
				f[i][j][0] = max(f[i][j][0],f[j][k][1] + (a[i] == a[j]?a[i]:0) + c[j + 1][i - 1] + (k > 0 && a[j + 1] == a[k - 1]?a[j + 1]:0));
				f[i][j][1] = max(f[i][j][1],c[j][i] + f[j][k][0]);
			}
			if(i == n) ans = max(ans,max(f[i][j][0],f[i][j][1]));	
		} 
	}
	cout << ans << endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		ans = 0;
		if(n <= 16){
			for(int i = 1;i <= n;i++) cin >> a[i];
			dfs(1);
			cout << ans << endl;
		}	
		else solve();
	}	
	return 0;
}
