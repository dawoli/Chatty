#include <bits/stdc++.h>
using namespace std;

long long n,m,ans=1,c[505],x;
char s[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='1')
			x++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if (x<m)
	{
		cout<<0;
		return 0;
	}
	sort(c+1,c+1+n);
	ans=1;
	for (int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
		cout<<ans<<" ";
	}
	cout<<ans%998244353;
}
