#include<bits/stdc++.h>
using namespace std;
long long n,k,a,u=0,ans=0,u2;
map<long long,long long> l1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	l1[0]=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a;
		u=a^u;
		u2=k^u;
		if(l1[u2])
		{
			ans++;
			l1.clear();
		}
		l1[u]++;
	}
	cout<<ans;
	return 0;
}
