#include <bits/stdc++.h>
using namespace std;
int a[20];
int k[20];
int n;
int ans = 0;
void dfs(int dep){
	if (dep > n){
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i - 1; j >= 1; j--){
				if(k[i] == k[j]){
					if(a[i] == a[j]) cnt += a[i];
					break;
				}
			}
		}
		ans = max(ans,cnt);
		return;
	}
	k[dep] = 1;
	dfs(dep + 1);
	k[dep] = 2;
	dfs(dep + 1);
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		} 
		dfs(1);
		cout << ans << endl;
	}
}
