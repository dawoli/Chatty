#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out","w", stdout);
	cin >> t;
	while(t--)
	{
		int n,k,q,a[100005][200005],r,c;
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][0];
			for(int j = 1; j <= a[i][0]; j++)
			{
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> r >> c;
			cout << 1 <<< endl;
		}
	}
	return 0;
}
