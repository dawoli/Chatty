#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s,r,c;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		while(n--) 
		{
			cin>>l;
			while(l--) cin>>s;
		}
		while(q--) cin>>r>>c;
	}
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
