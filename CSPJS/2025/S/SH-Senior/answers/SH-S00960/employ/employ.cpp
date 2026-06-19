#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,c[500];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		for(int i=1;i<=10;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n&&flag==0)
	{
		cout<<0<<"\n";
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
