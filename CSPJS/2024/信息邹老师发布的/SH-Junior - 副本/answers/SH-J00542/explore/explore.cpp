#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d;
string mp[1010];
bool vis[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		long long ans=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			cin>>mp[i];
			mp[i]=" "+mp[i];
		}
		while(k--){
			int xx=x,yy=y;
			switch(d){
				case 0:yy=y+1;break;
				case 1:xx=x+1;break;
				case 2:yy=y-1;break;
				case 3:xx=x-1;break;
			}
			if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]=='x'){
				d=(d+1)%4;
			}
			else{
				x=xx;
				y=yy;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
