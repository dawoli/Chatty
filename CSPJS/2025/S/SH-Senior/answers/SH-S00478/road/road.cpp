#include<bits/stdc++.h>
using namespace std;
const int BIG=1000001;
int n,m,k;
int u[BIG],v[BIG],w[BIG];
int suburb[11][10001];

void input()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int j=1;j<=k;j++)
	{
		scanf("%d",&suburb[j][0]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&suburb[j][i]);
		}
	}
}
bool spe_a()
{
	bool flag=true;
	for(int j=1;j<=k;j++)
	{
		if(suburb[j][0])
		{
			flag=false;
			break;
		}
	}
	return flag;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	if(k==0)
	{
		
	}
	else if(spe_a())
	{
		
	}
	else
	{
		
	}
	return 0;
}
