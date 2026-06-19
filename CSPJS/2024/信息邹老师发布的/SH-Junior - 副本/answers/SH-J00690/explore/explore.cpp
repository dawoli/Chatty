#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, xnow, ynow, dnow, xnew, ynew, ans, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string mp[1005];
bool vis[1005][1005];

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t --){
		cin >> n >> m >> k >> xnow >> ynow >> dnow;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i ++){
			cin >> mp[i];
			mp[i] = ' ' + mp[i];
		}
		vis[xnow][ynow] = 1;
		while(k --){
			xnew = xnow + dx[dnow];
			ynew = ynow + dy[dnow];
			if(xnew >= 1 && xnew <= n && ynew >= 1 && ynew <= m && mp[xnew][ynew] != 'x') vis[xnow = xnew][ynow = ynew] = 1;
			else dnow = dnow + 1 & 3;
		}
		ans = 0;
		for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(vis[i][j]) ++ ans;
		cout << ans << endl;
	}
	return 0;
}
