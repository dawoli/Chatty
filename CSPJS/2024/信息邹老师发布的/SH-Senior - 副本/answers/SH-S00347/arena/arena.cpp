#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int a[111111][1111];
int n,m;
int aa[111111],c[111111],x[111],z[1111];
struct node{
	int val,ans;
};
//int dfs(int l,int r,int h,int x,int id)
//{
//	if(x==1)
//	{
//		if(h>r) return l+r;
//		if(h==l)
//		{
//			if(a[x][id]) return l+r;
//			return ((a[l]>x)?l:r);
//		}
//		if(a[x][id]) return ((a[r]>x)?r:l);
//		return ((a[l]>x)?l:r);
//	}
//	int mid=(l+r)/2;
//	if(!a[x][id]) return (dfs(l,mid,h,x-1,id*2-1)>x)?;
//	dfs(mid+1,r,h,x-1,id*2);
//}
node dfs(int l,int r,int dep,int id,int maxc)
{
	if(dep==1)
	{
		if(l>maxc) return node{-1,l+r};
		if(l==maxc&&a[dep][id]) return node{-1,l+r};
		if(a[dep][id]) return node{2,(r>dep)?r:l};
		return  node{2,(l>dep)?l:r};
	}
	node lf=dfs(l,(l+r)/2,dep-1,id*2-1,maxc),rc=dfs((l+r)/2+1,r,dep-1,id*2,maxc);
	if(a[dep][id])
	{
		if(rc.val==-1) return node{NULL,NULL};
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>aa[i];
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	int k=ceil(log2(n));
	for(int i=k;i>=1;i--)
	{
		for(int l=1;l<=(1<<k-1);l++)
		{
			scanf("%1d",a[i][l]);
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=4;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			z[i]=aa[i]^x[i%4];
		}
		for(int i=1;i<=m;i++)
		{
			dfs(1,ceil(log2(c[i]))*ceil(log2(c[i])),c[i],ceil(log2(c[i])),1);
		}
	}
	return 0;
}
