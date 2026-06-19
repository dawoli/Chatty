#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,c[501],cnt,s[501];
char abc[501];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>abc;
	for(int i=0;i<n;i++)
	{
		s[i]=abc[i]-'0';
		if(s[i]==1) cnt++;
	}
	for(int i=0;i<n;i++) cin>>c[i];
	sort(c,c+n);
	if(cnt<m)
	{
		cout<<0<<endl;
	}
	if(cnt==n)
	{
		for(int i=1;i<=n;i++) ans=(ans*n)%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(m==1)
	{
		
		return 0;
	}
	if(cnt==m)
	{
		int idx;
		for(int i=0;i<n;i++)
		{
			if(c[i]>=1)
			{
				idx=i;
				break;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]==1)
			{
				idx++;
			}
		}
	}
	return 0;
}
