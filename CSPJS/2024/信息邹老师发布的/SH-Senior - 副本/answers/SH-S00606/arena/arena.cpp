#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],c[100005],k,x0,x1,x2,x3,t;
char r[105][105];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	int N=n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	while(N>0)
	{
		N/=2;
		k++;
	}
	k--;
	for (int i=1;i<=k;i++)
	{
		cin>>r[i];
	}
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>x0>>x1>>x2>>x3;
	}
	
	return 0;
}
