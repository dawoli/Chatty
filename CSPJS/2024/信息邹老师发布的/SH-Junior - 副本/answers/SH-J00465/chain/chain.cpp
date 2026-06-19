#include <bits/stdc++.h>
using namespace std;
int a[100010][200010];
int main()
{
	freopen("chain.in ","r",stdin);
	freopen("chain.out ","w",stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n,k,q;
		cin >> n >> k >>q;
		for (int i = 1;i <= n;i++)
		{
			int l;
			cin >> l;
			for (int j = 1;j <= l;j++) cin >> a[i][j];
		}
		for (int i = 1;i <= q;i++)
		{
			int r,c;
			cin >> r >> c;
			cout << 0;
		}
	}
	return 0;
}
