#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,x,y,d;
char s,mp[1005][1005];
bool dp[1005][1005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		int ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i=1 ; i<=n ; i++)
			for (int j=1 ; j<=m ; j++)
			{
				cin>>mp[i][j];
			}
		dp[x][y]=1;
		for (int i=1 ; i<=k ; i++)
		{
			int _x=x+dx[d],_y=y+dy[d];
			if (mp[_x][_y] == '.'  && _x >= 1 && _x <= n && _y >= 1 && _y <= m)
			{
				dp[_x][_y]=1;
				x=_x;
				y=_y;
			}
			else
			{
				d++;
				d= d%4; 
			}
		}
		for (int i=1 ; i<=n ; i++)
			for (int j=1 ; j<=m ; j++)
				if (dp[i][j])
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
