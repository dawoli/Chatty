#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m,c,k,g=0,a;
array<int,10> q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>c>>k;
	if(!n&&!m&&k==64)
	{
		cout<<(unsigned long long)-1+1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		g|=a;
	}
	for(int j=1;j<=m;j++)
	{
		int pi,q;
		cin>>pi>>q;
		p[j]=pi;
	}
	for(int i=1;i<=n;i++)
	{
		string b=DegToBin(i);
		int j=0;
		for(auto s:b)
		{
			bin[a[i]][j]=s;
			j++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<bin[a[i]].size();j++)
		{
			if(bin[i][j])s[j]=1;
		}
	}
	for(int i=1;i<=pow(2,k);i++)
	{	
		if(find(a.begin(),a.end(),i)!=a.end())
	}
}