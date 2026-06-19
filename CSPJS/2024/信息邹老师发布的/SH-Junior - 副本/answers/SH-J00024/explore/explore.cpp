#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d;
bool vis[1005][1005];
char c[1005][1005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		vis[x][y]=true;
		while(k--){
			int nx,ny;
			if(d==0){
				nx=x;
				ny=y+1;
			}else if(d==1){
				nx=x+1;
				ny=y;
			}else if(d==2){
				nx=x;
				ny=y-1;
			}else if(d==3){
				nx=x-1;
				ny=y;
			}
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&c[nx][ny]=='.'){
				vis[nx][ny]=true;
				x=nx;
				y=ny;
			}else{
				d=(d+1)%4;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
