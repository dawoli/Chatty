#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	int c[505];
	cin>>a;
	for(int i=1;i<=n;i++)cin>>c[i];
	int s[505]={};
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		s[i]=int(a[i]-48);
		if(s[i]==0)f=0;
	}
	sort(c+1,c+n+1);
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
			{
				cout<<0;
				return 0;
			}
			else 
			{
				long long ans=1;
				for(int i=1;i<=m;i++)
				{
					ans*=i;
					ans=ans%998244353;
				}
				
				cout<<ans;
				return 0;
			}
		}
		
	}
	if(f==1)
	{
		long long ans=1;
		for(int i=1;i<=n-1;i++)
		{
			ans*=i;
			ans=ans%998244353;
		}
				
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}
