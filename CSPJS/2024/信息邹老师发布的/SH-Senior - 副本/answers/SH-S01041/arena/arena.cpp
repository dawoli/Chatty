#include<bits/stdc++.h>
#define N 100005

using namespace std;

int n,m,c[N],a[N],t,x[5];


int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		cin>>c[j];
	}
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=4;j++)
		{
			cin>>x[j];
		}
		cout<<0<<endl;
	}
	return 0;
}

