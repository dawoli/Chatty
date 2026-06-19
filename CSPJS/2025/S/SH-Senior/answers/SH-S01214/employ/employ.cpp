#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	m=n;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		cin>>a;
		if(a==0)
		m--;
	}
	for(long long i=1;i<=m;i++)
	s=(s*(m-i+1))%998244353;
	cout<<s;
	
 } 
