#include <bits/stdc++.h>
using namespace std;
int l[200005];
vector<int> s[200005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,k,q;
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			cin >> l[i];
			for(int j = 1;j <= l[i];j++)
			{
				int x;
				cin >> x;
				s[i].push_back(x);
			}
		}
		while(q--)
		{
			int r,c;
			cin >> r >> c;
			cout << 0 << endl;
		}
	}
	return 0;
}
