#include<bits/stdc++.h>
using namespace std;

const int N=100005,INF=2147483647;
int a1[N],a2[N],a3[N];
int dp[202][202][202];
int ch[N],b[N];
int t1[N],t2[N],t3[N],ed[3];
bool cmp(int x,int y)
{
	return b[x]>b[y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,k1,k2,k3;
	int ans=0;
	bool flaga=1,flagb=1;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		ans=0;ed[1]=ed[2]=ed[3]=0;
		flaga=1,flagb=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a2[i]!=0||a3[i]!=0) flaga=0;
			if(a3[i]!=0) flagb=0;
			if(n>200)
			{
				if(a1[i]>=a2[i]&&a1[i]>=a3[i])
					ans+=a1[i],ch[i]=1,b[i]=min(a1[i]-a2[i],a1[i]-a3[i]),t1[++ed[1]]=i;
				else if(a2[i]>=a1[i]&&a2[i]>=a3[i])
					ans+=a2[i],ch[i]=2,b[i]=min(a2[i]-a1[i],a2[i]-a3[i]),t2[++ed[2]]=i;
				else if(a3[i]>=a1[i]&&a3[i]>=a2[i])
					ans+=a3[i],ch[i]=3,b[i]=min(a3[i]-a2[i],a3[i]-a2[i]),t3[++ed[3]]=i;
			}
		}
		if(flaga)
		{
			sort(a1+1,a1+1+n);
			for(int i=n;i>n/2;i--)
				ans+=a1[i];
			printf("%d\n",ans);
		}
		if(flagb)
		{
			for(int i=1;i<=n;i++)
				ans+=a1[i],b[i]=a1[i]-a2[i];
			sort(b+1,b+1+n);
			for(int i=1;i<=n/2;i++)
				ans-=b[i];
			printf("%d\n",ans);
		}
		else if(n<=200)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				for(k1=0;k1<i&&k1<=n/2;k1++)
					for(k2=0;k2+k1<i&&k2<=n/2;k2++)
					{
						k3=i-1-k1-k2;
						if(k1<n/2)
							dp[k1+1][k2][k3]=max(dp[k1+1][k2][k3],dp[k1][k2][k3]+a1[i]);
						if(k2<n/2)
							dp[k1][k2+1][k3]=max(dp[k1][k2+1][k3],dp[k1][k2][k3]+a2[i]);
						if(k3<n/2)
							dp[k1][k2][k3+1]=max(dp[k1][k2][k3+1],dp[k1][k2][k3]+a3[i]);
					}
			}
			ans=0;
			for(k1=0;k1<=n/2;k1++)
				for(k2=0;k2<=n/2;k2++)
				{
					k3=n-k1-k2;
					ans=max(ans,dp[k1][k2][k3]);
				}
			printf("%d\n",ans);
		}
		else
		{
			if(ed[1]>n/2)
			{
				sort(t1+1,t1+1+ed[1],cmp);
				for(int i=ed[1];i>n/2;i--)
					ans-=b[t1[i]];
			}
			else if(ed[2]>n/2)
			{
				sort(t2+1,t2+1+ed[2],cmp);
				for(int i=ed[2];i>n/2;i--)
					ans-=b[t2[i]];
			}
			else if(ed[3]>n/2)
			{
				sort(t3+1,t3+1+ed[3],cmp);
				for(int i=ed[3];i>n/2;i--)
					ans-=b[t3[i]];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
