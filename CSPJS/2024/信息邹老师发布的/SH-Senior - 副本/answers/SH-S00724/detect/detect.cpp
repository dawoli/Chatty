#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
	int l1,r1;
}c[100001];
bool cmp(Node x,Node y)
{
	return x.r1<y.r1;
}
int n,m,l,v,cur;
int a[100001],b[100001],d[100001],p[100001];
bool f[100001];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cur=0;
		cin>>n>>m>>l>>v;
		v=v*v;
		for(int i=1;i<=n;i++)
		{
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			a[i]=t3*2;
			b[i]=t2*t2-2*t3*t1;
			d[i]=t1;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]>p[m])
			{
				f[i]=false;
				continue;
			}
			if(a[i]>=0)
			{
				if(1ll*a[i]*p[m]+b[i]>1ll*v)
				{
					f[i]=true;
					cnt++;
				}
				else f[i]=false;
			}
			else
			{
				int l1=1,r=m;
				while(l1+1<r)
				{
					int mid=(l1+r)/2;
					if(p[mid]>=d[i])r=mid;
					else l1=mid;
				}
				if(p[l1]>=d[i])r=l1;
				if(1ll*a[i]*p[r]+b[i]>1ll*v)
				{
					f[i]=true;
					cnt++;
				}
				else f[i]=false;
			}
		}
		cout<<cnt<<" ";
		for(int i=1;i<=n;i++)
		{
			if(!f[i])continue;
			if(a[i]>=0)
			{
				int l1=1,r=m;
				while(l1+1<r)
				{
					int mid=(l1+r)/2;
					if(p[mid]>=d[i]&&1ll*a[i]*p[mid]+b[i]>1ll*v)r=mid;
					else l1=mid;
				}
				if(p[l1]>=d[i]&&1ll*a[i]*p[l1]+b[i]>1ll*v)r=l1;
				c[++cur]={r,m};
			}
			else
			{
				int l1=1,r=m;
				while(l1+1<r)
				{
					int mid=(l1+r)/2;
					if(p[mid]>=d[i])r=mid;
					else l1=mid;
				}
				if(p[l1]>=d[i])r=l1;
				int l2=r,r2=m;
				while(l2+1<r2)
				{
					int mid=(l2+r2)/2;
					if(1ll*a[i]*p[mid]+b[i]>1ll*v)l2=mid;
					else r2=mid;
				}
				if(1ll*a[i]*p[r2]+b[i]>1ll*v)l2=r2;
				c[++cur]={r,l2};
			}
		}
		sort(c+1,c+cur+1,cmp);
		int lst=0,ans=0;
		for(int i=1;i<=cur;i++)
		{
			if(c[i].l1<=lst)continue;
			else
			{
				lst=c[i].r1;
				ans++;
			}
		}
		cout<<m-ans<<endl;
	}
}
