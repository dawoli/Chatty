#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,ans;
int dp[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

char ma[1005][1005];

void s(int x1,int y1,int nd,int k)
{
	if(k==0) return;
	int x2,y2;
	x2=x1+dp[nd][0];
	y2=y1+dp[nd][1];
	if(ma[x2][y2]=='x' || (x2<1 || x2>n || y2<1 || y2>m))
	{
		int d=(nd+1)%4;
		s(x1,y1,d,k-1);
	}
	else
	{
		if(ma[x2][y2]!='v') ans++;
		ma[x2][y2]='v';
		s(x2,y2,nd,k-1);
	}
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>ma[i][j];
			}
		}
		ma[x][y]='v';
		ans=1;
		s(x,y,d,k);
		cout<<ans<<endl;
	}
	return 0;
}
