#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010];
int dx[10]={1,0,-1,0};
int dy[10]={0,1,0,-1};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		int n,m,t,x,y,st;
	    cin >> n >> m >> t >> x >> y >> st;
	    for (int i=1; i<=n; i++){
		    for (int j=1; j<=m; j++){
			    char c;
			    cin >> c;
			    a[i][j]=c;
		    }
	    }
        vis[y][x]+=1;
	    for (int i=1; i<=t; i++){
			int nx=x+dx[st];
			int ny=y+dy[st];
			if (nx>=1 && nx<=m && ny>=1 && ny<=n && a[ny][nx]!='x'){
				x=nx;
				y=ny;
				vis[ny][nx]+=1;
			}else{
				st=(st+1)%4;
			}   
		}
		int ans=0;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				if (vis[i][j]!=0){
					ans++;
				}
			}
		}
		cout << ans << endl;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				vis[i][j]=0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
