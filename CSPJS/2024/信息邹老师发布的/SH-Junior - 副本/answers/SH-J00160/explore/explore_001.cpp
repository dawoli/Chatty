#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char a[1005][1005];
//bool vis[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
	//freopen("explore.in","w",stdin);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		int n,m,k,x,y,d;
		cin >> n >> m >> k >> x >> y >> d;
		//memset(vis,0,sizeof(vis));
		//.emptyspace  x wrongspace   & walked
		string s;
		for (int i = 1;i <= n;i++){
			cin >> s;
			for (int j = 1;j <= m;j++){
				a[i][j] = s[j-1];
			}
		}
		int ans = 1;
		//2x & -> break
		//bool flag = false;
		for (int i = 1;i <= k;i++){
			int nx = x+dx[d],ny = y+dy[d];
			if (a[nx][ny] == 'x' || nx > n || nx < 1 || ny > m || ny < 1){
				d = (d+1)%4;
				continue;
			}
			else{
				if (a[nx][ny] != '&'){
					ans++;
				}
				a[x][y] = '&';
				x = nx;
				y = ny;

			}
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
