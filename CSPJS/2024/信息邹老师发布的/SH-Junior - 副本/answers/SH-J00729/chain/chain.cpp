#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int a[100005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
	}
	int r,c;
	while(q--)
	{
		cin>>r>>c;
		if(a[c]==0)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
	}
	return 0;
}
