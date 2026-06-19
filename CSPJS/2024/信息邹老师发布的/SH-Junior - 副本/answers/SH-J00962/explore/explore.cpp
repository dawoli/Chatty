#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
bool g[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,d,ans;
	cin>>T;
	for(int iii=1;iii<=T;iii++){
	bool flag=false;
	ans=0;
	char c;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
	    {
	    	cin>>c;
	    	if(c=='.') g[i][j]=true;
	    	else g[i][j]=false;
	    	vis[i][j]=false;
		}
	}
	vis[x][y]=true;
	ans++;
	for(int i=1;i<=k;i++)
	{
		while(/*x+dx[d]<1||x+dx[d]>n||y+dy[d]<1||y+dy[d]>m||*/!g[x+dx[d]][y+dy[d]])
		{
			d=(d+1)%4;
			i++;
			if(i==k)
			{
				flag=true;
				break;
			}
		}
		if(flag) break;
		x=x+dx[d];
		y=y+dy[d];
		if(vis[x][y]!=true) ans++;
		vis[x][y]=true;
	}
	cout<<ans<<endl;
    }
	return 0;
}
