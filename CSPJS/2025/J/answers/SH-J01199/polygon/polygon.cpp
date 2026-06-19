#include <bits/stdc++.h>
using namespace std;

long long a[5005],n,ans=0;

long long sum=0,maxx=0;

void dfs(int step)
{
//	printf("sum:%d maxx:%d step:%d ans:%d\n",sum,maxx,step,ans);	
	if(step>n)
	{
		if(sum>maxx*2)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	long long tmp_maxx=maxx,tmp_sum=sum;
	maxx=max(a[step],maxx);
	sum+=a[step];
	dfs(step+1);
	maxx=tmp_maxx;
	sum=tmp_sum;
	dfs(step+1);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}

