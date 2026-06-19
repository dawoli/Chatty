#include<bits/stdc++.h>
using namespace std;

int adfgjl;
int n,m,k,x,y,d;
char c[1111][1111];
map<int,map<int,bool> > mapp;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>adfgjl;
	while(adfgjl--)
	{
		int ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c[i][j];
				mapp[i][j]=false;
			}
		}
		ans++;
		mapp[x][y]=true;
		for(int i=1;i<=k;i++)
		{
			int x1=x+dx[d];
			int y1=y+dy[d];
			if(x1<1||y1<1||x1>n||y1>m||(c[x1][y1]=='x'))
			{
				d=(d+1)%4;
			}
			else 
			{
				x=x1;
				y=y1;
				if(mapp[x][y]==false)
				{
					ans++;mapp[x][y]=true;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0 ; 
}

