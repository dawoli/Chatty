#include <bits/stdc++.h>
using namespace std;
char map1[1005][1005]={'x'};
bool map2[1005][1005]={0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d;
	cin>>t;
	while(t--)
	{
		int ans1=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>map1[i][j];
			}
		}
		map2[x][y]=1;
		while(k--)
		{
			if(d==0)
			{
				y=y+1;
			}
			else if(d==1)
			{
				x=x+1;
			}
			else if(d==2)
			{
				y=y-1;
			}
			else if(d==3)
			{
				x=x-1;
			}
			if(map1[x][y]=='x'||x<1||x>n||y<1||y>m)
			{
				if(d==0)
			    { 
				    y=y-1;
				    d=1;
				    //cout<<d<<" ";
			    }
			    else if(d==1)
			    {
		    		x=x-1;
		    		d=2;
		    		//cout<<d;
			    }
			    else if(d==2)
			    {
			    	y=y+1;
			    	d=3;
			    	//cout<<d<<" ";
			    }
			    else if(d==3)
			    {
			    	x=x+1;
			    	d=0;
			    	//cout<<d<<" ";
			    }
			}
			else map2[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(map2[i][j]==1) ans1++;
			}
		}
		cout<<ans1<<endl;
	}
	return 0;
}
