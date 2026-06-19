#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char a[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		vis[x][y] = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		int xx,yy;
		for (int i = 1; i <= k; i++){
			if(d == 0) xx = x,yy = y + 1;
			if(d == 1) xx = x + 1,yy = y;
			if(d == 2) xx = x,yy = y - 1;
			if(d == 3) xx = x - 1,yy = y;	
			if(a[xx][yy] == '.' && xx >= 1 && xx <= n && yy >= 1 && yy <= m){
				vis[xx][yy] = true;
				x = xx;
				y = yy;
			}else{
				d++;
				if(d > 3) d = 0;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cnt += vis[i][j];
		cout << cnt << endl;
		memset(vis,0,sizeof vis);
	}
	return 0;
}
