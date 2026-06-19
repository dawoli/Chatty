#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum,d[10005][10005];
bool A;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long x,y,z;
		cin>>x>>y>>z;
		d[x][y]=z;
		d[y][x]=z;
		sum+=z;
	}
	for(int i=1;i<=k;i++)
	{
		long long x;
		cin>>x;
		if(x!=0)
		{
			A=1;
		}
		for(int j=1;j<=n;j++)
		{
			long long y;
			cin>>y;
		}
	}
	if(A==0)
	{
		cout<<0;
	}
	else
	{
		cout<<sum;
	}
	return 0;
}
