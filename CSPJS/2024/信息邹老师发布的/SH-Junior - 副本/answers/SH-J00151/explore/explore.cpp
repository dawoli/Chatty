#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t;
char mp[1009][1009];
bool vis[1009][1009];
long long d,x,y;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		long long ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=m;j++)
				cin>>mp[i][j];
		while(k--){
			long long wx,wy;
			if(d==0)
				wx=x,wy=y+1;
			if(d==1)
				wx=x+1,wy=y;
			if(d==2)
				wx=x,wy=y-1;
			if(d==3)
				wx=x-1,wy=y;
			if(mp[wx][wy]=='.'&&wx>=1&&wy>=1&&wx<=n&&wy<=m){
				x=wx,y=wy;
				if(vis[wx][wy]==0)
					ans++,vis[wx][wy]=1;
			}
			else
				d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
