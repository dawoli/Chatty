#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000000 + 5;
int n, a[MAXN], t;
int prer, preb;
int dfs(int u){
	if(u == n + 1)return 0;
	int ans = 0, tmp, tmp1;
	int col = rand() % 2;
	for(int i = 1; i <= 2; i++){
		if(col == 1){
			tmp = 0;
			if(prer == a[u])tmp += prer;
			tmp1 = prer;
			prer = a[u];
			tmp += dfs(u + 1);
			prer = tmp1;
		}
		else{
			tmp = 0;
			if(preb == a[u])tmp += preb;
			tmp1 = preb;
			preb = a[u];
			tmp += dfs(u + 1);
			preb = tmp1;
		}
		ans = max(ans, tmp);
		if(clock() >= 0.95 * CLOCKS_PER_SEC){
			return ans;
		}
		col = (col + 1) % 2;
	}
	//cout << u << ' ' << ans << endl;
	return ans;
}
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++)cin >> a[i];
		prer = 0;
		preb = 0;
		cout << dfs(1) << endl;
	}
    return 0;
}
