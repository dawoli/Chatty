#include<bits/stdc++.h>
using namespace std;
int t;
char mp[1005][1005];
int n,m;
int k;
int xs,ys,ds;
bool vis[1005][1005];
int ans=0;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&xs,&ys,&ds);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[xs][ys]=1;
		while(k--){
			int xx,yy;
			xx=xs;
			yy=ys;
			if(ds==0)	yy++;
			else if(ds==1)	xx++;
			else if(ds==2)	yy--;
			else if(ds==3)	xx--;
			if(!(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]=='x')){
				xs=xx,ys=yy;
				vis[xs][ys]=1;
			}
			else ds=(ds+1)%4;
			
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])	ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

