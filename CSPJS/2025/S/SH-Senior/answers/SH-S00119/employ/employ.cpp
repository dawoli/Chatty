#include<bits/stdc++.h>
using namespace std;
long long n,ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>s;
	for(long long i=1;i<=n;i++)
	{
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}
