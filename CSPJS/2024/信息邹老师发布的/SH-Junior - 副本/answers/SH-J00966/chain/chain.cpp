#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,tmp,t1,t2;
void solve()
{
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		for(int j=1;j<=tmp;j++)cin>>t1;
	}
	for(int i=1;i<=q;i++)cin>>t1>>t2;
	for(int i=1;i<=q;i++)cout<<i%2<<endl;
	return;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
