//GL@17SXYZ Y#C*GF@24
#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,xx,yy,dd,ans=0;
char MAP[1010][1010];
int vis[1010][1010];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		ans=1;
		memset(vis,0,sizeof vis);
		cin >> n >> m >> k >> xx >> yy >> dd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> MAP[i][j];
			}
		}
		vis[xx][yy]=1;
		while(k--){
			int nx=xx+dir[dd][0];
			int ny=yy+dir[dd][1];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && MAP[nx][ny]=='.'){
				xx=nx;
				yy=ny;
				if(!vis[nx][ny]){
					ans++;
					vis[nx][ny]=1;
				}
			}
			else{
				dd+=1;
				dd%=4;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
