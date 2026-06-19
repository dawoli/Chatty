#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, ans, x, y, d;
bool vis[1005][1005];
string s[1005];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		memset(vis, 0, sizeof(vis));
		for(int i = 1;i <= n;i++){
			cin>>s[i];
			s[i] = " "+s[i];
		}
		ans = 1;
		vis[x][y] = 1;
		while(k--){
			int tx = x+dx[d], ty = y+dy[d];
			if(!tx || tx > n || !ty || ty > m || s[tx][ty] == 'x'){
				d = (d+1)%4;
				continue;
			}
			x = tx;
			y = ty;
//			cout<<tx<<ty<<endl;
			if(!vis[x][y]) ans++;
			vis[x][y] = 1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
