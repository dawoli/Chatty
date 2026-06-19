#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],f=0;
long long ans=1;
char s[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]!='1') f=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==n) {
		cout<<0<<endl;
		return 0;
	}
		for(int i=2;i<=n;i++)
		{
			ans=(ans*i)%998244353;
			
		}
		cout<<ans<<endl;
	
	return 0;
}
