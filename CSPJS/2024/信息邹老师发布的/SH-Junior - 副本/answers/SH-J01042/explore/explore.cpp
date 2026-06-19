#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n,m,k;

int sx,sy,sd;
struct pos {
	int x,y;
};
pos go(int nx,int ny,int nd) {
	if(nd == 0) return {nx,ny+1};
	if(nd == 1) return {nx+1,ny};
	if(nd == 2) return {nx,ny-1};
	return {nx-1,ny};
}
signed main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--) {
		char s[1011][1011];
		bool cnt[1011][1011];
		memset(cnt,false,sizeof cnt);
		cin >> n >> m >> k;
		cin >> sx >> sy >> sd;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) cin >> s[i][j];
		}
		int ans = 1;
		for(int i = 1;i <= k;i++) {
			pos nxt = go(sx,sy,sd);
//			cout << nxt.x << " " << nxt.y << endl;
			if(nxt.x < 1||nxt.y > m||nxt.x > n||nxt.y < 1||s[nxt.x][nxt.y]=='x') {
				sd = (sd+1)%4;
				continue;
			}else {
				sx=nxt.x,sy=nxt.y;
				if(!cnt[sx][sy]) {
					cnt[sx][sy] = 1;
					ans++;
				}
				
			}
		}
		cout << ans << endl;
	}
	return 0;
}
