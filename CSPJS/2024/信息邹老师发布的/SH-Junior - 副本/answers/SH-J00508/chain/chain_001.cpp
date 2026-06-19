#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int l[100001];
int a[100001][200001];
int r[100001],c[100001];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>l[j];
			for(int x=1;x<=l[j];x++)
			{
				cin>>a[j][x];
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
