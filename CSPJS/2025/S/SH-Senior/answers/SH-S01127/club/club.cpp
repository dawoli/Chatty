#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, n, a[N][4], ans;
struct Node
{
	int i, j;
	bool operator<(const Node &tmp) const
	{
		int d1 = 1e9, d2 = 1e9;
		for(int x = 1; x <= 3; x++)
		{
			if(j != x && a[i][j] - a[i][x] >= 0)
				d1 = min(d1, a[i][j] - a[i][x]);
			if(tmp.j != x && a[tmp.i][tmp.j] - a[tmp.i][x] >= 0)
				d2 = min(d2, a[tmp.i][tmp.j] - a[tmp.i][x]);
		}
		return d1 > d2;	
	}	
};
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		priority_queue<Node> pq[4];
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				cin >> a[i][j];
		for(int i = 1; i <= n; i++)
		{
			int mx = -1, id = 0;
			for(int j = 1; j <= 3; j++)
				if(a[i][j] > mx)
					mx = a[i][j], id = j;
			pq[id].push({i, id});
		}
		while(pq[1].size() > n / 2 || pq[2].size() > n / 2 || pq[3].size() > n / 2)
		{
			int mx = -1, id = 0;
			for(int i = 1; i <= 3; i++)
				if((signed)pq[i].size() > (signed)mx)
					mx = pq[i].size(), id = i;
			Node u = pq[id].top();
			pq[id].pop();
			int mn = 2e9, mnid = 0;
			for(int i = 1; i <= 3; i++)
				if(a[u.i][u.j] - a[u.i][i] >= 0 && i != u.j && a[u.i][u.j] - a[u.i][i] < mn)
					mn = a[u.i][u.j] - a[u.i][i], mnid = i;
			pq[mnid].push({u.i, mnid});
		}
		for(int i = 1; i <= 3; i++)
			while(pq[i].size())
				ans += a[pq[i].top().i][pq[i].top().j], pq[i].pop();
		cout << ans << endl;
	}
	return 0;
}
// ÉÙÓðÅ£±Æ 
