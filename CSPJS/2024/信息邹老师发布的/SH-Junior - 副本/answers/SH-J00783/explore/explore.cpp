#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int T,n,m,k,x,y,d;
string l;
int map[1005][1005];
int dir1[4]={0,1,0,-1},
    dir2[4]={1,0,-1,0};
 
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>l;
			for(int j=0;j<m;j++)
			{
				if(l[j]=='x') map[i][j+1]=0;
				if(l[j]=='.') map[i][j+1]=1;
			}
		}
		
		map[x][y]=2;
		
		while(k--)
		{
			x=x+dir1[d];y=y+dir2[d];
			if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y])
			{
				map[x][y]=2;
			}
			else
			{
				x=x-dir1[d];y=y-dir2[d];
				d=(d+1)%4;
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(map[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
