#include<bits/stdc++.h>
using namespace std;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
bool ma[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	short T;
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d,ans=0;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char p;
				cin>>p;
				if(p=='x')ma[i][j]=1;
				else ma[i][j]=0;
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		ans++;
		while(k--){
			int xx,yy;
			xx=x+dx[d];yy=y+dy[d];
			if(1<=xx && xx<=n && 1<=yy && yy<=m && ma[xx][yy]==0){
				x=xx;y=yy;
				if(vis[x][y]==0){
					ans++;
					vis[x][y]=1;
				}
			}else{
				d++;
				d=d%4;
			}
		}cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
