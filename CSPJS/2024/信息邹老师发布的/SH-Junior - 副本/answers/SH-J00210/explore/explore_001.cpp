#include <bits/stdc++.h>
using namespace std;
long long dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
long long T,n,m,k,sx,sy,sd,vis[1005][1005],ans;
string a[1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while (T--){
		cin >> n >> m >> k >> sx >> sy >> sd,memset(vis,0,sizeof(vis)),ans = 0,vis[sx][sy] = 1;
		for (long long i = 1;i <= n;i++) cin >> a[i],a[i] = " " + a[i];
		while (k--){
			long long nx = sx + dx[sd],ny = sy + dy[sd];
			if (nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == 'x') sd = (sd + 1) % 4;
			else sx = nx,sy = ny,vis[nx][ny] = 1;
		}
		for (long long i = 1;i <= n;i++) for (long long j = 1;j <= m;j++) ans += vis[i][j];
		cout << ans << endl;
	}
	return 0;
}
