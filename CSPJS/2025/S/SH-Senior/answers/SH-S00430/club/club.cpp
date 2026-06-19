#include<bits/stdc++.h>
using namespace std;
int a[100010][4],ma1[100010],ma2[100010],cnt[4],d[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			ma1[i]=-1;
			ma2[i]=-1;
		}
		for(int j=1;j<=3;j++)
		{
			cnt[j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>=ma1[i])
				{
					if(ma1[i]>=0)
					{
						ma2[i]=ma1[i];
						ma1[i]=a[i][j];
					}
					else ma1[i]=a[i][j];
				}
				else if(a[i][j]>=ma2[i])
				{
					ma2[i]=a[i][j];
				}
			}
		}
		int ans=0,mcnt=0,tot=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]==ma1[i])
				{
					cnt[j]++;
					ans+=a[i][j];
				}
			}
		}
		int chf=0;
		for(int i=1;i<=n;i++)
		{
			if(ma1[i]==ma2[i])
			{
				chf+=ma1[i];
			}
		}
		mcnt=max(cnt[1],cnt[2]);
		mcnt=max(mcnt,cnt[3]);
		//for(int j=1;j<=3;j++)cout<<cnt[j]<<" ";
		if(mcnt>n/2)
		{
			int dcha=mcnt-n/2;
			for(int j=1;j<=3;j++)
			{
				if(cnt[j]==mcnt)
				{
					for(int i=1;i<=n;i++)
					{
						if(a[i][j]==ma1[i])
						{
							d[++tot]=ma1[i]-ma2[i];
						}
					}
				}
			} 
			sort(d+1,d+tot+1);
			for(int i=1;i<=dcha;i++)
			{
				ans-=d[i];
			}
		}
		ans-=chf;
		cout<<ans<<endl;
	}
	return 0;
}
