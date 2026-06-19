#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int u,v,w;
}a[1000010];
int fa[10010];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int t)
{
	if(fa[t]==t)
	{
		return t;
	}
	return fa[t]=find(fa[t]);
}
long long t[10010];
void differ()
{
	for(int i=1;i<=m;i++)
	{
		int u1,v1;
		long long w1;
		cin>>u1>>v1>>w1;
		a[i].u=u1;
		a[i].v=v1;
		a[i].w=w1;
	}
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		int g;
		cin>>g;
		for(int l=1;l<=n;l++)
		{
			cin>>t[l];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				cnt++;
				a[cnt].u=j;
				a[cnt].v=k;
				a[cnt].w=t[j]+t[k];
			} 
		}
	}
	
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	long long els=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u1=a[i].u;
		int v1=a[i].v;
		if(find(u1)==find(v1))continue;
		fa[find(u1)]=v1;
		els+=a[i].w;
		ans++;
		if(ans==n-1)break;
	}
	cout<<els<<endl;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k>0)
	{
		differ();
		exit(0);
	}
	for(int i=1;i<=m;i++)
	{
		int u1,v1;
		long long w1;
		cin>>u1>>v1>>w1;
		a[i].u=u1;
		a[i].v=v1;
		a[i].w=w1;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	long long cnt=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u1=a[i].u;
		int v1=a[i].v;
		if(find(u1)==find(v1))continue;
		fa[find(u1)]=v1;
		cnt+=a[i].w;
		ans++;
		if(ans==n-1)break;
	}
	cout<<cnt<<endl;

	return 0;
}

