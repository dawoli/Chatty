#include<bits/stdc++.h>
using namespace std;
int c[10005][10005],bu[10005][10005],vis[10005],ans=0;;
int main()
{
	freopen("read.in","r",stdin);
	freopen("read.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		c[x][y]=z;
		c[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>bu[i][0]; 
		for(int j=1;j<=m;j++)
		{
			cin>>bu[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			int minn=1e9+1,minj=0;
			for(int j=i+1;j<=n;j++)
			{
				if(vis[j]==0&&c[i][j]!=0)
				{
					minn=min(minn,c[i][j]);
					if(minn==c[i][j])
					{
						minj=j;
					} 
				}
				
			}
			for(int j=1;j<=k;j++)
			{
				for(int p=i+1;p<=n;p++)
				{
					if(vis[p]==0)
					{
						minn=min(minn,bu[j][0]+bu[j][i]+bu[j][p]);
						if(minn==bu[j][0]+bu[j][i]+bu[j][p])
						{
							minj=j;
						}
					}
					
				} 
			}
			vis[minj]=1;
			vis[i]=1;
			ans+=minn;
			cout<<"check:"<<minn<<endl;
		}	
	}
	cout<<ans<<endl;
	return 0;
} 
