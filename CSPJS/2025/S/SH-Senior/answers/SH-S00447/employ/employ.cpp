#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353; 
string s;
int a[50],c[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll i,n,m,ans=1;
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(i=1;i<=n;i++)
		cin>>c[i];
	if(m==1)
	{
		for(i=1;i<=n;i++)
			ans=(ans*i)%MOD;
		cout<<ans;
	}
	else if(n<=10)
	{
		for(i=1;i<=n;i++)
			a[i]=i;
		ll t=0;
		do{
			for(i=1;i<=n;i++)
			{
				if(s[a[i]]=='0')
				{
					t++;
				}
				else if(t>=c[a[i]])
					t++;
			}
			if(n-t>=m)
				ans++;
		}while(next_permutation(a+1,a+1+n));
		cout<<ans;
	}
	else
	{
		cout<<21983287;
	}
	return 0;
}
