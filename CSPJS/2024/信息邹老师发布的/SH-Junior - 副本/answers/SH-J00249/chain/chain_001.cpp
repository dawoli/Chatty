#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int n, k, q;
		vector<int> s[100001];
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			int l;
			cin >> l;
			for(int j = 0;j < l;j++)
			{
				int x;
				cin >> x;
				s[i].push_back(x);
			}
		}
		while(q--)
		{
			int r, c;
			bool can = false;
			cin >> r >> c;
			for(int i = 1;i <= n;i++)
			    for(int j = 0;j < s[i].size();j++)
			        if(s[i][j] == c)
			        {
			        	can = true;
			        	break;
					}
			if(!can)
			    cout << 0 << '\n';
			else
			    cout << 1 << '\n';
		}
	}
	
	return 0;
}
