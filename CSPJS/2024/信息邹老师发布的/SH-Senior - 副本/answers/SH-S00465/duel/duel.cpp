#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=1000000000;
	int x=a[1];
	int ans=0;
	int cnt=0;
	int sum=1;
	for(int i=2;i<=n+1;i++)
	{
		if(a[i]==x)
		{
			sum++;
		}
		else
		{
			if(sum>=cnt)
			{
				ans+=sum-cnt;
			}
			cnt=max(sum,cnt);
			sum=1;
			x=a[i];
		}
	}
	cout<<ans;
	return 0;
}
