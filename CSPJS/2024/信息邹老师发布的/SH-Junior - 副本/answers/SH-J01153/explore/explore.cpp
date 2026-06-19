#include <iostream>
#include <cstdio>
using namespace std;

int xn[3];
int yn[3];
int p,n,m,k,x,y,d;
int cnt=0;
char dp[1005][1005];
int vis[1005][1005];
int dfs(int x,int y,int k,int d)
{
	
	if(k==0)
	{
		return cnt+1;
		
	}
	
	int bx=x+xn[d];
	int by=y+yn[d];
	
	
	if(!vis[bx][by]&&dp[bx][by]!='x'&&bx<=n&&bx>=1&&by<=m&&by>=1)
	{
		vis[bx][by]=1;
		cnt++;
		//cout<<cnt<<" ";
		dfs(bx,by,k-1,d);
	}
	else if(vis[bx][by]==1&&dp[bx][by]!='x'&&bx<=n&&bx>=1&&by<=m&&by>=1)
	{
		dfs(bx,by,k-1,d);
	}
	else
	{
		
		dfs(x,y,k-1,(d+1)%4);
	}
	
	
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	xn[0]=0;
	xn[1]=1;
	xn[2]=0;
	xn[3]=-1;
	yn[0]=1;
	yn[1]=0;
	yn[2]=-1;
	yn[3]=0;
	cin>>p;
	for(int s=1;s<=p;s++)
	{
		cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i =1;i<=n;i++)
		{
			for(int j =1;j<=m;j++)
			{
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		for(int i =1;i<=n;i++)
		{
			for(int j =1;j<=m;j++)
			{
				cin>>dp[i][j];
			}
		}
		cout<<dfs(x,y,k,d)<<endl;
	}
	return 0;
}

