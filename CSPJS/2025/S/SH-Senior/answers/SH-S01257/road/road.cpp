#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cnt;
struct stu{
	int u,v,w;
}q[1005];
bool f[1005];
bool cmp(stu x,stu y)
{
	return x.w<=y.w;
}
void dij()
{
	int pos=1;
	while(cnt<n-1)
	{
		if(f[q[pos].u]==0||f[q[pos].v]==0)
		{
			ans+=q[pos].w;
			f[q[pos].u]=1,f[q[pos].v]=1;
		}
		pos++;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		int h;
		cin>>h;
		for(int j=1;j<=n;j++)
		{
			int fs;
			cin>>fs;
		}
	}
	sort(q+1,q+m+1,cmp);
	dij();
	cout<<ans;
	return 0;
}
