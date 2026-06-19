#include<bits/stdc++.h>
using namespace std;
char ma[1005][1005];
int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool visit[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k,x,y,d,sum=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>ma[i][j];
		memset(visit,false,sizeof(visit));
		visit[x][y]=true;
		while(k--)
		{
			if(ma[x+a[d][0]][y+a[d][1]]=='x' or x+a[d][0]<1 or x+a[d][0]>n or y+a[d][1]<1 or y+a[d][1]>m)
				d=(d+1)%4;
			else
			{
				x=x+a[d][0];
				y=y+a[d][1];
				if(!visit[x][y])
					sum++;
				visit[x][y]=true;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
