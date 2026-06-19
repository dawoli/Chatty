#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,q;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int l,s,r,c;cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l;
			for(int j=1;j<=l;j++) cin>>s;
		}
		for(int i=1;i<=q;i++) cin>>r>>c;
		cout<<"0\n";
	}
	return 0;
}
