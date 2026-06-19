#include<bits/stdc++.h>
using namespace std;
#define int long long
struct road{int u,v,w;}a[1100005];
int n,m,k,f[11005],ans=-1;
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(x);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
bool check()
{
	int t=find(1);
	bool flag=1;
	for(int i=2;i<=n;i++)
		if(find(i)!=t)
			flag=0;
	return flag;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1,x;i<=k;i++) 
	{
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			a[m+i*(j-1)+j].u=m+i;
			a[m+i*(j-1)+j].v=j;
			cin>>a[m+i*(j-1)+j].w;
		}
	}
	int cnt=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m+k*n;i++)
		if(a[i].w==0)
			merge(a[i].v,a[i].u);
	while(!check())
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i]!=f[j])
				{
					int add;
					merge(i,j);
					for(int k=1;k<=m;k++) 
						if(a[k].u==i&&a[k].v==j)
						{
							add=a[k].w;
							break; 
						}
					for(int k=m+1;k<=m+k*n;k++) 
						if(a[k].u==i&&a[k].v==f[j])
						{
							add=min(add,a[k].w);
							break;
						}
					for(int k=m+1;k<=m+k*n;k++) 
						if(a[k].u==f[i]&&a[k].v==j)
						{
							add=min(add,a[k].w);
							break;
						}
					cnt+=add;
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
