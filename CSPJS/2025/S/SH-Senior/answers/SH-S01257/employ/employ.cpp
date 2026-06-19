#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,cnt,qz[100005];
int c[10005];
string s;
long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=cnt)
		{
			cnt++;
		}
	}
	n-=cnt;
	if(n<m)
	{
		cout<<0;
		return 0;
	}
	if(n==m)
	{
		cout<<1;
		return 0;
	}
	for(long long i=m;i<=n;i++)
	{
		ans=i/(i-m+1)%mod;
	}
	cout<<ans;
	return 0;
}
