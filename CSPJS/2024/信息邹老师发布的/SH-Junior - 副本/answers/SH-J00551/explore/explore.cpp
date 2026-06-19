#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int	dfs()
{
	for(int i=1;i<=1005;i++)
		for(int j=1;j<=1005;j++)
			b[i][j]=0;
	int n,m,k,x,y,d;
	cin>>n>>m>>k>>x>>y>>d;
		for(int s=1;s<=n;s++)
			for(int j=1;j<=m;j++)
				cin>>a[s][j];
	int sum=1; 
		b[x][y]=true;
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		for(int i=1;i<=k;i++)
		{
			int qx=x+dx[d];
			int qy=y+dy[d];
			if(qx>0&&qy>0&&qx<=n&&qy<=m&&a[qx][qy]!='x')
			{
				if(b[qx][qy]==0)
					sum++;
				x=qx;
				y=qy;
				b[qx][qy]=1;
			}
			else
			{
				d++;
				d%=4;
			}
		}
	return sum;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		
		cout<<dfs()<<endl; 
	}
	return 0;	
} 
