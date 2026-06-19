#include <bits/stdc++.h>
using namespace std;

long long n,m,k,d[15],ans;
struct node
{
	int v,w;
}a[20005];
void check(int z,int fa)
{
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int flag=1;
	if (k==0)
		flag=0;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].v=v;
		a[u].w=w;
		a[v].w=w;
		a[v].v=u;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>d[i];
		if (d[i]!=0)
			flag=0;
		for (int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			a[j].w=w;
			a[j].v=i+10000;
			a[i+10000].w=w;
			a[i+10000].v=j;
			if (w!=0)
			{
				flag=0;
			}
		}
	}
	if (flag==1)
	{
		cout<<0;
		return 0; 
	}
	check(1,0);
	cout<<ans;
	return 0;
}
