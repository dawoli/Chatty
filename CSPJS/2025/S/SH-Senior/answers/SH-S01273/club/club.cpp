#include<bits/stdc++.h>
using namespace std;
long long t,ans,n,ba[10],cnt[10],b[10],a[10],cha1[100010],cha2[100010],cha3[100010],pl;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		pl=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%lld",&a[j]);
				b[j]=a[j];
			}
			sort(a+1,a+4);
			ans+=a[3];
			for(int j=1;j<=3;j++)
			{
				if(b[j]==a[3])
				{
					cnt[j]++;
					if(j==1) cha1[cnt[j]]=a[3]-a[2];
					if(j==2) cha2[cnt[j]]=a[3]-a[2];
					if(j==3) cha3[cnt[j]]=a[3]-a[2];
					break;
				}
			}
		}
		for(int i=1;i<=3;i++) ba[i]=cnt[i];
		sort(cnt+1,cnt+4);
		for(int i=1;i<=3;i++)
		{
			if(ba[i]==cnt[3])
			{
				pl=i;
				break;
			}
		}
		if(pl==1) sort(cha1+1,cha1+cnt[3]+1);
		else if(pl==2) sort(cha2+1,cha2+cnt[3]+1);
		else if(pl==3) sort(cha3+1,cha3+cnt[3]+1);
		for(int i=1;i<=cnt[3]-n/2;i++)
		{
			if(pl==1) ans-=cha1[i];
			else if(pl==2) ans-=cha2[i];
			else if(pl==3) ans-=cha3[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
