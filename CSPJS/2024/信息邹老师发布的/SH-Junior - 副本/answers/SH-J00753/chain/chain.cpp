#include <iostream>
#include <cstdio>
using namespace std;
vector<int > v[100010];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,n,k,q;
	while (T--)
	{
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++)
		{
			int l;
			cin >> l;
			for (int j = 1; j <= l; j++;)
			{
				int x;
				cin >> x;
				v[i].push_back(x);
			}
		}
		while (q--)
		{
			int r,c;
			cin >> r >> c;
			if (r + c << 1) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
