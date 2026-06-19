#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m;
string s;
int c[505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(m==1)
	{
		int x=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				x=i+1;
				break;
			}
		}
		if(!x)cout<<0<<"\n";
		else
		{
			int y=upper_bound(c+1,c+n+1,x)-c;
			if(y>n)cout<<0<<"\n";
			long long ans=n-y+1;
			for(int i=2;i<n;i++)
			{
				ans*=i;
				ans%=MOD;
			}
			cout<<ans<<endl;
		}
	}
	else if(m==n)
	{
		bool b=true;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				b=false;
				break;
			}
		}
		if(b==false||c[1]==0)cout<<0<<"\n";
		else
		{
			long long ans=1;
			for(int i=2;i<=n;i++)
			{
				ans*=i;
				ans%=MOD;
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		cout<<0<<"\n";
	}
	return 0;
}
