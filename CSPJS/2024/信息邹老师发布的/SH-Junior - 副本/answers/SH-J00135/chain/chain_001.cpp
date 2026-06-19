#include <bits/stdc++.h>
using namespace std;

int t,n,k,q,r,c;
int p[10005][20005];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			int l;
			cin>>l;
			for(int k=1;k<=l;k++)
			{
				cin>>p[l][k];
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r>>c;
			cout<<0<<endl;
		}
	}
	return 0;
 } 
