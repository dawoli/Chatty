#include<bits/stdc++.h>
using namespace std;
struct node
{
	int mx;
	int sum[5];
};
bool cmp(node a,node b)
{
	return a.mx>b.mx;
}
node p[100010];
map<int,map<int,map<int,int> > > mp;
int n,mx;
void dfs(int a,int b,int c,int num,int deep)
{
	mx=max(mx,num);
	if(mp[a][b][c]>num||deep>=n)
	{
		return;
	} 
	mp[a][b][c]=num;
	if(a+1<=n/2)dfs(a+1,b,c,num+(p[(deep+1)].sum[1]),deep+1);
	if(b+1<=n/2)dfs(a,b+1,c,num+(p[(deep+1)].sum[2]),deep+1);
	if(c+1<=n/2)dfs(a,b,c+1,num+(p[(deep+1)].sum[3]),deep+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
	{
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p[i].sum[1],&p[i].sum[2],&p[i].sum[3]);
		}
		mp.clear();
		dfs(0,0,0,0,0);
		cout<<mx<<endl;
		mx=0;
	} 
	return 0;	
} 
