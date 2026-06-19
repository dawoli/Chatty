#include<bits/stdc++.h>
using namespace std;
int t; 
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			int l;
			cin>>l; 
			for(int x=1;x<=l;x++)
			{
				int p;
				cin>>p;
			}
		}
		for(int j=1;j<=q;j++)
		{
			int r,c;
			cin>>r>>c;
			if((r+c)%3==0)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
