#include<bits/stdc++.h>
using namespace std;
int b[10010]={ },fa[10010]={ };
int n,m,k;
long long ans=0;
struct nmnm
{
	int now,to,va;
};
nmnm a[1000100];
int cmp(nmnm x,nmnm y)
{
	return x.va<y.va;
}
int findset(int xx)
{
	if(fa[xx]!=xx)
	{
		fa[xx]=findset(fa[xx]);
	}
	return fa[xx];
}
void pd(int ji,int xb)
{
	for(int i=1;i<=m;i++)
	{
		if(xb==n)
		{
			return ;
		}
		int l=findset(a[ji].now);
		int r=findset(a[ji].to);
		if(l!=r)
		{
			fa[l]=fa[r];
			ans+=a[ji].va;
			xb++;
		}
		ji++;
	}
		
//		pd(ji+1,xb);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].now>>a[i].to>>a[i].va;
	}
	for(int i=1;i<=k;i++)
	{
		int xx;
		cin>>xx;
		
		for(int j=1;j<=xx;j++)
		{
			int mm;
			cin>>mm;
		}
	}
	sort(a,a+m+1,cmp);
	pd(1,1);
	cout<<ans;
	return 0;
 } 
