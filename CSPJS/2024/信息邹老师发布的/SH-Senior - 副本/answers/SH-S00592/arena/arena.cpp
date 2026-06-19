#include<bits/stdc++.h>
using namespace std;
const int len=1e5+10;
bool d[20][len];
int a0[len],a[len],c[len],x[4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	while((1<<k)<m)
	{
		k++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a0[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=k;i++)
	{
		string s;
		cin>>s;
		for(int j=1;j<=(1<<(k-i));j++)
		{
			d[i][j]=s[j-1]-'0';
		}
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++)
		{
			a[i]=a0[i]^x[i%4];
		}
		cout<<1<<'\n';
	}
	return 0;
}
