#include<bits/stdc++.h>
using namespace std;

long long t,n,a[100005][10],maxa[100005],maxb[100005],maxc[100005],cnt[10];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(maxa,0x3F3F3F3F,sizeof(maxa));
		memset(maxb,0x3F3F3F3F,sizeof(maxb));
		memset(maxc,0x3F3F3F3F,sizeof(maxc));
		memset(cnt,0,sizeof(cnt));
		long long ans=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
			long long maax=max({a[i][1],a[i][2],a[i][3]});
			ans+=maax;
			if(a[i][1]==maax)
				maxa[i]=a[i][1]-max(a[i][2],a[i][3]),
				cnt[1]++;
			else if(a[i][2]==maax)
				maxb[i]=a[i][2]-max(a[i][1],a[i][3]),
				cnt[2]++;
			else
				maxc[i]=a[i][3]-max(a[i][1],a[i][2]),
				cnt[3]++;
		}
		if(cnt[1] > n/2)
		{
			sort(maxa+1,maxa+1+n);
			for(int i=1;i<= cnt[1]-n/2 ;i++)
				ans-=maxa[i];
		}
		else if(cnt[2] > n/2)
		{
			sort(maxb+1,maxb+1+n);
			for(int i=1;i<= cnt[2]-n/2 ;i++)
				ans-=maxb[i];
		}
		else if(cnt[3] > n/2)
		{
			sort(maxc+1,maxc+1+n);
			for(int i=1;i<= cnt[3]-n/2 ;i++)
				ans-=maxc[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
