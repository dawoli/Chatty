#include<bits/stdc++.h>
using namespace std;
int v[100001],t[10001],w[10001];
int main()
{
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	for(int i=1;i<=n;i++)
		cin>>t[i]>>w[i];
	cout<<sum;
	return 0;
}
