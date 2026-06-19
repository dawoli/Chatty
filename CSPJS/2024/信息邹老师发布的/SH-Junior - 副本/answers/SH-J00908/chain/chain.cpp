#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while (t--)
	{
		int n,k,q;
		int l[100005];
		for (int i=1;i<=n;i++)
		{
			cin>>l[i];
			for (int j=1;j<=l[i];j++)
			{
				int a;
				cin>>a;
			}
		}
		for (int i=1;i<=q;i++)
		{
			int r,c;
			cin>>r>>c;
			int ans=(r+c)%2;
			cout<<ans;
		}
	}
	return 0;
}
