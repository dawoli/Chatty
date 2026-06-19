#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans,n,m;
void reset();
void dfs(int x,int y,int d,int k){
	if(k==0)
	{
		cout<<ans<<endl;
		return ;
	}
	int nx=x+dx[d],ny=y+dy[d];
	if(nx<1 || ny<1 || nx>n || ny>m)
		dfs(x,y,(d+1)%4,k-1);
	else
	{
		if(mp[nx][ny]!='.')
			dfs(x,y,(d+1)%4,k-1);
		else
		{
			if(!vis[nx][ny])
			{
				ans++;
				vis[nx][ny]=true;
			}
			dfs(nx,ny,d,k-1);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		ans++;
		vis[x][y]=true;
		dfs(x,y,d,k);
		ans=0;
		reset();
	}
	return 0;
}
void reset(){
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=false;
			}
		}
}
