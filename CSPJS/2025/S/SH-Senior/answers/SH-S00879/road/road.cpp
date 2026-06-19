#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
long long ans;
int n,m,k,cnt;
int c[10001],a[11][10001],idx[10001];
bool b[10001]
struct towards{
	int t,w;
};
struct paths{
	vector<towards> a;
	int cnt=0;
}pth[10001];
void dfs(int x,int h,int val)
{
	if(h==n-1) return;
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",u,v,w);
		pth[u].a[pth[u].cnt].t=v;
		pth[u].a[pth[u].cnt++].w=w;
		pth[v].a[pth[v].cnt].t=u;
		pth[v].a[pth[v].cnt++].w=w;
	}
	dfs(1,1,0);
	return 0;
}
