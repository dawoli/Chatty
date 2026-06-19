#include<iostream>
using namespace std;		
int n,m,k,x,y,d,t;
char s[1001][1001];
int visit[1001][1001];
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","r",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k>>x>>y>>d;
		visit[x][y]=1;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
				cin>>s[j][l];
		}
		for(int j=1;j<=k;j++)
		{
			int tx=x,ty=y;
			if(d==0)
				ty++;
			if(d==1)
				tx++;
			if(d==2)
				ty--;
			if(d==3)
				tx--;
			if(tx>=1 and tx<=n and ty>=1 and ty<=m and s[tx][ty]=='.')
			{
				x=tx;
				y=ty;
				visit[tx][ty]=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
				if(visit[j][l]==1)
				{
					visit[j][l]=0;					
					ans++;
				}

		}
		cout<<ans<<endl;
	}
	
} 
