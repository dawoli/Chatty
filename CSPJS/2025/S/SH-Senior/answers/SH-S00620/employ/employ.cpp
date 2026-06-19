#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long s=1;
	for(int i=1;i<=m;i++)
	{
		s*=i;
	}
	int a[10100];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<s%998244353;
	return 0;
}
