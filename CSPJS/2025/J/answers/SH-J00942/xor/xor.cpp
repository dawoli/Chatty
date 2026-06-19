#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt1=0;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cnt1++;
		}
	}
	if(k==1)
	{
		cout<<cnt1<<endl;
	}
	else
	{
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&flag==1)
			{
				flag=0;
				ans++;
			}
			else if(a[i]==1&&flag==0)
			{
				flag=1;
			}
			if(flag==0&&a[i]==0)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
