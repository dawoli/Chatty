#include <bits/stdc++.h>
using namespace std;
int n,m,k=0,v[10001],t[100001];
bitset<500001> f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int v1,s;
		cin>>v1>>s;
		for (int j=1;j<=s;j*=2)
		{
			v[++k]=v1*j;
			s-=j;
		}
		if (s)v[++k]=v1*s;
	}
	for (int i=1;i<=m;i++)
		cin>>t[i];
	f[0]=true;
	for (int i=1;i<=k;i++)
	{
		for (int j=500000;j>=v[i];j--)
			if (f[j-v[i]])f[j]=true;
	}
	for (int i=1;i<=m;i++)
	{
		if (f[t[i]])cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}