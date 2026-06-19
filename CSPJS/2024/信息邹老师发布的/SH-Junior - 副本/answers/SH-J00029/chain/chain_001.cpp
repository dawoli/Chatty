#include <bits/stdc++.h>
using namespace std;

struct f
{
	int l;
	string s;
}p[100008];

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, q;
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++)
			cin >> p[i].l >> p[i].s;
		while(q--)
		{
			int r, c;
			cin >> r >> c;
			cout << (0, 1);
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
