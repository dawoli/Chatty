#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1e5+5;
const double eps=1e-8;
int d[N],v[N],a[N],p[N];
int st[N],ed[N];
double r[N];
struct node{
	int s,e;
}q[N];
bool cmp(node x,node y)
{
	return x.e<y.e;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1; i<=n; i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0)
			{
				if(v[i]>V) r[i]=d[i]-1;
				else r[i]=2e9;
			}
			else r[i]=d[i]+(1.0*V*V-v[i]*v[i])/2/a[i];
		}
		for(int i=1; i<=m; i++) cin>>p[i];
		int cnt=0;
		for(int i=1; i<=n; i++)
		{
			int st,ed;
			if(a[i]>=0)
			{
				if(r[i]<=L)
				{
					cnt++;
					st=upper_bound(p+1,p+m+1,max(r[i],(double)d[i]))-p;
					ed=m;
					if(st>ed) cnt--;
					else q[cnt].s=st,q[cnt].e=ed;
				}
			}
			else if(a[i]<0)
			{
				if(r[i]>d[i])
				{
					ed=lower_bound(p+1,p+m+1,r[i])-p-1;
					st=lower_bound(p+1,p+m+1,d[i])-p;
					cnt++;
					if(st>ed) cnt--;
					else q[cnt].s=st,q[cnt].e=ed;
				}
			}
		}
		cout<<cnt<<" ";
		sort(q+1,q+cnt+1,cmp);
		int lt=1,sum=min(1,cnt),minid=q[1].s;
		for(int i=2;i<=cnt;i++)
		{
			if(q[i].s>q[lt].e)
			{
				sum++;
				lt=i;
			}
			minid=min(minid,q[i].s);
		}
		cout<<m-sum<<endl;
	}
	return 0;
}
