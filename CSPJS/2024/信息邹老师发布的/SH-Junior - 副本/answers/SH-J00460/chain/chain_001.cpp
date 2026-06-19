#include <bits/stdc++.h>
using namespace std;
int a[1005][2005];
int r[100005];
int c[100005];
int l[200005];
bool hav[200005];
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
		for (int i = 1; i <= n; i++)
		{
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++)
			{
				cin >> a[i][j];
				hav[a[i][j]] = true;
			}
		}
		for (int qq = 1; qq <= q; qq++)
		{
			cin >> r[qq] >> c[qq];
			if (r[qq] == 1)
			{
				bool flag = false; 
				for (int i = 1; i <= n; i++)
				{
					int lpos = 200005, rpos = -1;
					for (int j = 1; j <= l[i]; j++)
					{
						if (a[i][j] == 1 && rpos == -1)
							lpos = j;
						if (a[i][j] == c[qq] && lpos != 200005)
							rpos = j;
					}
					if (rpos - lpos + 1 <= k && rpos - lpos + 1 >= 2 && flag == false)
					{
						cout << 1 << endl;
						flag = true;
					}
				}
				if (flag == false)
					cout << 0 << endl;
			}
		}
	}
	return 0; 
}

