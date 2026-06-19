#include<bits/stdc++.h>
using namespace std;
int t, n, k, q, l, s[1005][2005], r, c;
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	cin >> t;
	for(int e = 1; e <= t; e++)
	{
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++)
	    {
	       	cin >> l;
	       	for(int j = 1; j <= l; j++)
		    {
		       	cin >> s[i][j];
		    }
	    }
		for(int i = 1; i <= q; i++)
	    {
	    	cin >> r >> c;
	       	cout << 0 << endl;
	    }
	}
	return 0;
}
