#include<bits/stdc++.h>

using namespace std;
int t;
int ans;
int vis[1007][1007];
int n,m,k,sx,sy,d;
char f[1007][1007];
void dfs(int x,int y,int di,int step){
	if(step==0){
		ans++;
		return;
	}
	int nx=0;
	int ny=0;
	if(di==0){
		nx=x;
		ny=y+1;
	}
	if(di==1){
		nx=x+1;
		ny=y;
	}
	if(di==2){
		nx=x;
		ny=y-1;
	}
	if(di==3){
		nx=x-1;
		ny=y;
	}
	if(nx<=n&&ny<=m&&nx>=1&&ny>=1&&f[nx][ny]!='x'){
		if(vis[nx][ny]==0){
			vis[nx][ny]=1;
			ans++;
		}
		dfs(nx,ny,di,step-1);
	}
	else{
		di=(di+1)%4;
		dfs(x,y,di,step-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>sx>>sy>>d;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>f[j][l];
			}
		}
		vis[sx][sy]=1;
		ans=0;
		dfs(sx,sy,d,k);
		cout<<ans<<endl;
	}
	return 0; 
} 
