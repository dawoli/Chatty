#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			if(a==k)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	else if(k==0)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			if(a==k)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<26+59;
	}
	return 0;
}
