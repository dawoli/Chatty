#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int round;
	for(round=1;round<=t;round++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		
		bool jungle[n+2][m+2];
		bool ans[n+2][m+2];
		int i,j;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				ans[i][j]=false;
			}
		}
		ans[x][y]=true;
		
		
		jungle[0][0]=false;
		jungle[n+1][0]=false;
		jungle[0][m+1]=false;
		jungle[n+1][m+1]=false;
		for(i=1;i<=n;i++)
		{
			jungle[i][0]=false;
			jungle[i][m+1]=false;
		}
		for(i=1;i<=m;i++)
		{
			jungle[0][i]=false;
			jungle[n+1][i]=false;
		}
		char place;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>place;
				if(place=='.')
				{
					jungle[i][j]=true;
				}
				else
				{
					jungle[i][j]=false;
				}
			}
		}
		////////////////////
		/*for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=m+1;j++)
			{
				cout<<jungle[i][j];
			}
			cout<<endl;
		}*/
		
		
		
		
		for(i=1;i<=k;i++)
		{
			if(d==0)
			{
				if(jungle[x][y+1]==false)
				{
					d+=1;
					d=d%4;
				}
				else
				{
					ans[x][y+1]=true;
					y+=1;
				}
			}
			else if(d==1)
			{
				if(jungle[x+1][y]==false)
				{
					d+=1;
					d=d%4;
				}
				else
				{
					ans[x+1][y]=true;
					x+=1;
				}
			}
			else if(d==2)
			{
				if(jungle[x][y-1]==false)
				{
					d+=1;
					d=d%4;
					continue;
				}
				else
				{
					ans[x][y-1]=true;
					y-=1;
				}
			}
			else if(d==3)
			{
				if(jungle[x-1][y]==false)
				{
					d+=1;
					d=d%4;
					continue;
				}
				else
				{
					ans[x-1][y]=true;
					x-=1;
				}
			}
		}
		int ans_num=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(ans[i][j]==true)
				{
					ans_num+=1;
				}
			}
		}
		
		////////////////////
		/*cout<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cout<<ans[i][j];
			}
			cout<<endl;
		}*/
		
		
		
		
		
		cout<<ans_num<<endl;
	}
	return 0;
}
