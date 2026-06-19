#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=10020,Maxm=1000010;
int n,m,t,q[20][Maxn],fa[Maxn],cnt,ans;
struct node{
	int u,v,w;
}a[Maxm];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	bool f=0;
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>q[i][j];
			if(j==0&&q[i][j]!=0) f=1;
		}
	}
	if(f==0)
	{
		vector<node> b;
		for(int i=1;i<=m;i++)
		{
			b.push_back(a[i]);
		}
		for(int k=1;k<=t;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					b.push_back({i,j,q[k][i]+q[k][j]});
				}
			}
		}
		m=m+n*n*t;
		sort(b.begin(),b.end(),cmp);
		for(int i=1;i<=m;i++)
		{
	//		cout<<b[i].u<<" "<<b[i].v<<endl;
			int l=find(b[i-1].u),r=find(b[i-1].v);
			if(l!=r)
			{
				cnt++;
				ans+=b[i-1].w;
				fa[l]=r;
			}
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
//		cout<<a[i].u<<" "<<a[i].v<<endl;
		int l=find(a[i].u),r=find(a[i].v);
		if(l!=r)
		{
			cnt++;
			ans+=a[i].w;
			fa[l]=r;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
