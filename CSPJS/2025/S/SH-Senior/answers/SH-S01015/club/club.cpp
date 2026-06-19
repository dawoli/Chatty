#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005][5],cnt[5],d[100005],ans;
ll b[100005],v=1,tt,dy;//可以更改的差值 
ll p[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		v=1,ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				p[i]=1,cnt[1]++;
				d[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>a[i][3])
			{
				p[i]=2,cnt[2]++;
				d[i]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else
			{
				p[i]=3,cnt[3]++;
				d[i]=a[i][3]-max(a[i][1],a[i][2]);
			}
			ans+=a[i][p[i]];
		}
		if(cnt[1]*2<=n&&cnt[2]*2<=n&&cnt[3]*2<=n)
		{
			printf("%lld\n",ans);
			continue;
		}
		if(cnt[1]*2>n) tt=1;
		else if(cnt[2]*2>n) tt=2;
		else tt=3;
		dy=cnt[tt]-n/2;
		b[0]=0;
		for(int i=1;i<=n;i++)
			if(p[i]==tt) b[v++]=d[i];
		b[v]=0;
		sort(b+1,b+v);
		for(int i=1;i<=dy;i++) ans-=b[i];
		printf("%lld\n",ans);
	}
	return 0;
}
