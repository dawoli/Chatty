#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, q;
		cin >> n >> k >> q;
		int l[100000];
		int a[200001] = {};
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> l[i];
			int s;
			for (int j = 0; j < l[i]; ++j)
			{
				cin >> s;
				a[s] += 1;
			}
		}
		int r[100000], c[100000];
		for (int i = 0; i < q; ++i)
		{
			cin >> r[i] >> c[i];
			if (a[c[i]] == 0)
			{
				cout << 0 << endl;
			}
			else if (r[i] == 1 && c[i] == 1)
			{
				cout << 0 << endl; 
			}
			else if (r[i] == 1 && c[i] > k)
			{
				cout << 0 << endl; 
			}
			else if (r[i] == n && c[i] > k)
			{
				cout << 0 << endl; 
			}
			else
			{
				cout << 1 << endl; 
			}
		}
	}
	
	return 0;
}
