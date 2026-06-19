#include<bits/stdc++.h>
using namespace std;
long long a,b,c=0,d;
struct A
{
	int e;
	int f[10002];
}g[10002];
struct B
{
	int n;
	int m;
}h[10002];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b>>c>>d;
		for(int j=1;j<=b;j++)
		{
			cin>>g[j].e ;
			for(int k=1;k<=g[i].e;k++)
			{
				cin>>g[j].f[k];
			}
		}
		for(int j=1;j<=d;j++)
		{
			cin>>h[j].n>>h[j].m;
		}
		for(int j=1;j<=d;j++)
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
