#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int d[N],p[N];
int a[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int spA=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&d[i]);
		spA=min(spA,d[i]);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	if(n<=10)
	{
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=i;
		do
		{
			int cnt0=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==0)
				{
					cnt0++;
					continue;
				}
				if(cnt0>=p[a[i]])
				{
					cnt0++;
					continue;
				}
				cnt++;
			}
			if(cnt>=m) ans++;
		}while(next_permutation(a+1,a+1+n));
		
		cout<<ans;
	}
	else if(spA)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=p[i]>0;
		if(cnt==0)
		{
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=2;i<=cnt;i++)
			ans=(ans*i)%mod;
		cout<<ans;	
	}
	return 0;
}
