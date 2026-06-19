#include<bits/stdc++.h>
using namespace std;
int t,n,k,l,x,q,r,c,a[10000];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l;
			for(int i=1;i<=l;i++)
			{
				cin>>x;
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r>>c;
			if(c==1)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
