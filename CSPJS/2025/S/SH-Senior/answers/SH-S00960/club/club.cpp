#include<bits/stdc++.h>
using namespace std;
long long T;
long long a[100005][5],b[100005],s1[100005],s2[100005],s3[100005],f1[100005],f2[100005],f3[100005];
void solve()
{
	long long cnt1=0,cnt2=0,cnt3=0;
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	memset(f3,0,sizeof(f3));
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		b[i]=max(a[i][1],max(a[i][2],a[i][3]));
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==a[i][1])
		{
			cnt1++;
			f1[i]=1;
			ans+=a[i][1];
		}
		else if(b[i]==a[i][2])
		{
			cnt2++;
			ans+=a[i][2];
			f2[i]=1;
		}
		else if(b[i]==a[i][3])
		{
			cnt3++;
			ans+=a[i][3];
			f3[i]=1;
		}
	}
	long long i=1;
	while(cnt1>n/2)
	{
		long long minn=100005;
		long long bj=-1;
		for(int j=1;j<=n;j++)
		{
			if(f1[j]==1)
			{
				if(a[j][1]-a[j][2]<minn)
				{
					minn=a[j][1]-a[j][2];
					bj=j;
				}
				if(a[j][1]-a[j][3]<minn)
				{
					minn=a[j][1]-a[j][3];
					bj=j;
				}
			}
		}
		ans=ans-minn;
		cnt1--;
		f1[bj]=0;
		i++;
	}
	while(cnt2>n/2)
	{
		long long minn=100005;
		long long bj=-1;
		for(int j=1;j<=n;j++)
		{
			if(f2[j]==1)
			{
				if(a[j][2]-a[j][1]<minn)
				{
					minn=a[j][2]-a[j][1];
					bj=j;
				}
				if(a[j][2]-a[j][3]<minn)
				{
					minn=a[j][2]-a[j][3];
					bj=j;
				}
			}
		}
		ans=ans-minn;
		cnt2--;
		f2[bj]=0;
		i++;
	}
	while(cnt3>n/2)
	{
		long long minn=100005;
		long long bj=-1;
		for(int j=1;j<=n;j++)
		{
			if(f3[j]==1)
			{
				if(a[j][3]-a[j][1]<minn)
				{
					minn=a[j][3]-a[j][1];
					bj=j;
				}
				if(a[j][3]-a[j][2]<minn)
				{
					minn=a[j][3]-a[j][2];
					bj=j;
				}
			}
		}
		ans=ans-minn;
		cnt3--;
		f3[bj]=0;
		i++;
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
