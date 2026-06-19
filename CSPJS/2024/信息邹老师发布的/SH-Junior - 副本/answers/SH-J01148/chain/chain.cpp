#include<bits/stdc++.h>
using namespace std;
long long T, n, k, q, l, s, cnt[200005], r, c;
vector <vector <int>> pl;
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> n >> k >> q;
		for(int j = 1; j <= n; j++)
		{
			cin >> l;
			for(int k = 1; k <= l; k++)
			{
				cin >> s;
				pl[j].push_back(s);
				cnt[s]++;
			}
		}
		for(int j = 1; j <= q; j++)
		{
			cin >>r>>c;
			if(cnt[c] == 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
	} 
	return 0;
} 
