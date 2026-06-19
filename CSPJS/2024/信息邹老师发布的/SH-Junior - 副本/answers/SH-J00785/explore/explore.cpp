#include <bits/stdc++.h>
using namespace std;
int nex[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char ma[1020][1020];
bool v[1020][1020];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k,x,y,d,sum=1;
		cin>>n>>m>>k>>x>>y>>d;
		v[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>ma[i][j];
			}
		}
		while(k--)
		{
			int tx=x+nex[d][0],ty=y+nex[d][1];
			if(tx<1||tx>n||ty<1||ty>m||ma[tx][ty]=='x') d=(d+1)%4;
			else
			{
				x=tx,y=ty;
				if(v[x][y]==0)
				{
					sum++;
					v[x][y]=1;
				}
			}
		}
		cout<<sum<<"\n";
		memset(v,0,sizeof(v));
	}
}
