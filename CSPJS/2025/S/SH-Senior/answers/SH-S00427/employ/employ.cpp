#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,c[2],d[2];
long long ans;
bool p[1001];
string s;
int main()
{
	freopen("emlpoy.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') c[1]++;
		else c[0]++;
	}
	if(c[1]<m)
	{
		cout<<0<<endl;
		return 0;
	}
	if(c[1]==n&&m==n)
	{
		ans=1;
		for(int i=n;i>=1;i--)
		{
			ans*=i;
			ans=ans%mod;
		}
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
