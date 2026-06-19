#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char mp[1010][1010];
int vis[1010][1010];
int a[4]={0,1,0,-1};
int b[4]={1,0,-1,0};
void dfs(int x,int y,int d){
	int xx=x+a[d];
	int yy=y+b[d];
	if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&mp[xx][yy]=='.'){
		x=xx;
		y=yy;
		if(!vis[x][y])ans++;
		vis[x][y]=1;
		k--;
		if(k==0){
			cout<<ans+1<<endl;
			return;
		}
		dfs(x,y,d);
	}
	else{
		d++;
		if(d>=4) d=0;
		k--;
		if(k==0){
			cout<<ans+1<<endl;
			return;
		}
		dfs(x,y,d);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,d);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
