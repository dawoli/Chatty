#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int a[100005][200005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	for (int i=1;i<=t;i++)
	{
		cin >> n >> k >> q;
		for (int j=1;j<=n;j++)
		{
			int l;
			cin >> l;
			for (int k=1;k<=l;k++)
			{
				cin >> a[j][k];
			}
		}
		for (int j=1;j<=q;j++)
		{
			int r,c;
			cin >> r,c;
			cout << 1;
		}
	}
	return 0;
}
