#include<bits/stdc++.h>
using namespace std;
const int INF=1e6+7;
int n,t,cnt[10];
long long ans=0;
struct node
{
	int a[10],mx,mxn,del;
}p[100010];
int chmx(int x)
{
	p[x].mx=0;
	p[x].mxn=0;
	p[x].del=INF;
	for(int i=1;i<=3;i++)
	{
		if(p[x].mx<p[x].a[i])
		{
			p[x].mx=p[x].a[i];
			p[x].mxn=i;
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(i==p[x].mxn)
			continue;
		if(p[x].mx-p[x].a[i]<p[x].del)
			p[x].del=p[x].mx-p[x].a[i];
	}
	return 0;
}
int cmp(node x,node y)
{
	return x.del<y.del;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
			chmx(i);
			ans+=p[i].mx;
			cnt[p[i].mxn]++;
//			cout<<i<<" "<<p[i].mx<<" "<<p[i].mxn<<" "<<p[i].del<<endl;
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				sort(p+1,p+n+1,cmp);
				for(int j=1;j<=n;j++)
				{
					if(cnt[i]<=n/2)
						break;
					if(p[j].mxn!=i)
						continue;
					ans-=p[j].del;
					cnt[p[j].mxn]--;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
