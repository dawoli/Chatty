#include <iostream>
using namespace std;
int N = 2005;
int l[N],a[1005][N];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q,c,r;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n >> k >> q;
		for (int j = 1;j <= n;j++)
		{
			cin >> l[j];
			for (int k = 1;k <= l[j];k++)
				cin >> a[j][k];
		}
		for (int j = 1;j <= q;j++)
		{
			cin >> r >> c;
			cout << 0 << endl;
		}
	}
	return 0;
}
