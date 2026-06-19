#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int b[105];
int work2()
{
	int ret=0;
	int re=0;
	int bl=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			if(re==b[i])
			{
				ret+=b[i];
			}
			re=b[i];
		}
		else
		{
			if(bl==b[i])
			{
				ret+=b[i];
			}
			bl=b[i];
		}
	}
	return ret;
}
void work()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<(1<<n);i++)
	{
		int x=i;
		for(int j=1;j<=n;j++)
		{
			a[j]=x&1;
			x>>=1;
		}
		ans=max(ans,work2());
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}
