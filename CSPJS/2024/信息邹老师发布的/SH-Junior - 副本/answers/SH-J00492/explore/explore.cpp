#include<bits/stdc++.h>
using namespace std;

int t;
int n,m,k;
char mp[1010][1010];
int mpvis[1010][1010]={0};
int ans;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	int l=0;
	while(t--)
	{
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		
		ans=0;
		memset(mpvis,0,sizeof(mpvis));
		
		if(mpvis[x][y]==0)
		{
			mpvis[x][y]=1;
			ans++;
		}
		for(int i=1;i<=k;i++)
		{
			
			int ntx,nty;
			if(d==0)
			{
				ntx=x;
				nty=y+1;
			}
			if(d==1)
			{
				ntx=x+1;
				nty=y;
			}
			if(d==2)
			{
				ntx=x;
				nty=y-1;
			}
			if(d==3)
			{
				ntx=x-1;
				nty=y;
			}
			
			if(ntx>0&&ntx<=n&&nty>0&&nty<=m&&mp[ntx][nty]=='.')
			{
				x=ntx;
				y=nty;
			}
			else
			{
				d=(d+1)%4;
			}
			if(mpvis[x][y]==0)
			{
				mpvis[x][y]=1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
