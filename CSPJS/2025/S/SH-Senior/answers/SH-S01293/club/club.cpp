//100pts???
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,b[5],cnt[5],ans,k;
struct member
{
	ll a[5],d1,d2,used,Max,Mid,Min;
}p[100005],q[100005];
bool cmp1(member a,member b)
{
	return a.d1>b.d1;
}
bool cmp2(member a,member b)
{
	return a.d2>b.d2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=k=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&b[1],&b[2],&b[3]);
			p[i].a[1]=b[1];
			p[i].a[2]=b[2];
			p[i].a[3]=b[3];
			sort(b+1,b+4);
			p[i].d1=b[3]-b[2];
			p[i].d2=b[2]-b[1];
			p[i].used=p[i].Max=p[i].Mid=p[i].Min=0;
			for(int j=1;j<=3;j++)
			{
			//	printf("%lld ",b[j]);
				if(p[i].a[j]==b[3]&&!p[i].Max) p[i].Max=j;
				else if(p[i].a[j]==b[2]&&!p[i].Mid) p[i].Mid=j;
				else if(p[i].a[j]==b[1]&&!p[i].Min) p[i].Min=j;
			}
		//	printf("\n%lld %lld %lld\n",p[i].Max,p[i].Mid,p[i].Min);
		}
		sort(p+1,p+n+1,cmp1);
		for(int i=1;i<=n;i++)
			if(cnt[p[i].Max]<n/2)
			{
				ans+=p[i].a[p[i].Max];
				cnt[p[i].Max]++;
				p[i].used=1;
			}
		for(int i=1;i<=n;i++)
			if(!p[i].used) q[++k]=p[i];
		sort(q+1,q+k+1,cmp2);
		for(int i=1;i<=k;i++)
			if(cnt[q[i].Mid]<n/2)
			{
				ans+=q[i].a[q[i].Mid];
				cnt[q[i].Mid]++;
				q[i].used=1;
			}
		for(int i=1;i<=k;i++)
			if(!q[i].used) ans+=q[i].a[q[i].Min];
		printf("%lld\n",ans);
	}
	return 0;
}
