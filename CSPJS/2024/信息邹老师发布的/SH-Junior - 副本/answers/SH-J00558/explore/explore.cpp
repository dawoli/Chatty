#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,a[1005][1005],an[1005][1005],ans;
string f;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>f;
			for(int j=1;j<=m;j++)
			{
				if(f[j-1]=='.')
				{
					a[i][j]=1;
				}
				else
				{
					a[i][j]=2;
				}
				an[i][j]=0;
			}
		}
		ans++;
		an[x][y]=1;
		while(k--)
		{
			if(d==0)
			{
				if((y+1<=m)&&(a[x][y+1]==1))
				{
					y+=1;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else if(d==1)
			{
				if((x+1<=n)&&(a[x+1][y]==1))
				{
					x+=1;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else if(d==2)
			{
				if((y-1>=1)&&(a[x][y-1]==1))
				{
					y-=1;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else
			{
				if((x-1>=1)&&(a[x-1][y]==1))
				{
					x-=1;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			if(an[x][y]==0)
			{
				an[x][y]=1;
				ans++;
			 } 
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
