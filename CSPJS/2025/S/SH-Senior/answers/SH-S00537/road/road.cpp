#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x,y,z,num;
}v[1100005];
int n,m,k,c[15],cnt,fa[10015],tot,cnt2;
long long ans=1e18,C;
bool vis[15],flagA;
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int find(int x)
{
	if(fa[x]==0||fa[x]==x)
	{
		fa[x]=x;
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		v[++cnt]={x,y,z,0};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c+i);
		if(c[i]!=0)flagA=1;
		for(int j=1;j<=n;j++)
		{
			int a;
			scanf("%d",&a);
			v[++cnt]={j,n+i,a,i};
		}
	}
	sort(v+1,v+cnt+1,cmp);
	for(int op=0;op<=(1<<k)-1;op++)
	{
		if(!flagA)
		{
			op=(1<<k)-1;
		}
		C=0;
		memset(fa,0,sizeof(fa));
		memset(vis,0,sizeof(vis));
		cnt2=0,tot=n-1;
		for(int i=1;i<=k;i++)
		{
			if(op&(1<<(i-1)))
			{
				C+=c[i];
			}
		}
		for(int i=1;i<=cnt&&cnt2<tot;i++)
		{
			if((v[i].num==0||(op&1<<(v[i].num-1)))&&find(v[i].x)!=find(v[i].y))
			{
				C+=v[i].z;
				cnt2++;
				if(v[i].x>n&&!vis[v[i].x-n])
				{
					tot++;
					vis[v[i].x-n]=1;
				}
				if(v[i].y>n&&!vis[v[i].y-n])
				{
					tot++;
					vis[v[i].y-n]=1;
				}
				merge(v[i].x,v[i].y);
			}
			if(C>ans)
			{
				break;
			}
		}
		//cout<<op<<" "<<C<<endl;
		ans=min(ans,C);
	}
	cout<<ans;
	return 0;
}
