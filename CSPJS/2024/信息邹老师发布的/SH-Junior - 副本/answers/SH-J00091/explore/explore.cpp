#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int t;
//int m,n,k,x,y,d;
int reach[1005][1005];
int map_[1005][1005];
//int op[1000005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int m,n,k,x,y,d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		char c;
		//memset(op,sizeof(op),0);
		memset(reach,sizeof(reach),0);
		memset(map_,sizeof(map_),0);
		int cnt=1;
		reach[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c;
				if(c=='x')
				{
					map_[i][j]=0;
				}
				else if(c=='.')
				{
					map_[i][j]=1;
				}
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<map_[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i=1;i<=k;i++)
		{
			int tx,ty;
			if(d==0)
			{
				tx=x,ty=y+1;
			}
			else if(d==1)
			{
				tx=x+1,ty=y;
			}
			else if(d==2)
			{
				tx=x,ty=y-1;
			}
			else if(d==3)
			{
				tx=x-1,ty=y;
			}
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&map_[tx][ty]==1)
			{
				x=tx,y=ty;
				reach[tx][ty]++;
				if(reach[x][y]==1)
				{
					cnt++;
				}
			}
			else
			{
				d=(d+1)%4;
			}
			//cout<<x<<y<<endl;
		}
	//	cout<<cnt<<endl;
		int cnt1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(reach[i][j]>0)
				{
					cnt1++;
				}
			}
		}
		cout<<cnt1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
