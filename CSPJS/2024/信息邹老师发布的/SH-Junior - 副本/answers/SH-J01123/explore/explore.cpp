#include<bits/stdc++.h>
using namespace std;
char s;
bool vis[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,x,y,d,ans=0,dx,dy;
		for(int i=0;i<=1004;i++)
			for(int j=0;j<=1004;j++)vis[i][j]=false;
		cin>>n>>m>>k>>x>>y>>d;
		vis[x][y]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		for(int i=1;i<=k;i++){
			if(d==0)dx=x,dy=y+1;
			if(d==1)dx=x+1,dy=y;
			if(d==2)dx=x,dy=y-1;
			if(d==3)dx=x-1,dy=y;
			if(a[dx][dy]=='.')x=dx,y=dy,vis[x][y]=true;
			else d+=1,d%=4;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)if(vis[i][j])ans++;
		cout<<ans<<endl;
	}
	return 0;
}
