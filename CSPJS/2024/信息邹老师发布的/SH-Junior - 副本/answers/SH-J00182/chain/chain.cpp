# include <bits/stdc++.h>
using namespace std;
typedef int ll;

const int N = 200010;
struct node {ll l, id;};
ll T, n, k, qs;
ll len[N];
vector <ll> a[N];
queue <node> q[N];
queue <queue<node> > q2[N];
bool dp[110][N];

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dp[i][j] = false;
			}
		}
		map <ll, ll> vis;
		scanf("%d%d%d", &n, &k, &qs); 
		for (int i = 0; i < N; i++) a[i].clear();
		for (int i = 0; i < N; i++)
		{
			while (!q[i].empty()) q[i].pop();
			while (!q2[i].empty()) q2[i].pop();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &len[i]);
			a[i].push_back(0);
			for (int j = 1; j <= len[i]; j++)
			{
				ll num;
				scanf("%d", &num);
				a[i].push_back(num);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			queue <node> p;
			p.push({a[i][1], i});
			vis[a[i][1]]++;
//			cout << a[i][1] << " ";
			for (int j = 2; j <= len[i]; j++)
			{
				while ((ll)p.size() >= k) p.pop();
				q2[a[i][j]].push(p);
				vis[a[i][j]]++;
//				cout << a[i][j] << " ";
				p.push({a[i][j], i});
			}
//			cout << endl;
		}
		for (int i = 0; i < N; i++)
		{
			while (!q2[i].empty())
			{
//				cout << "..";
				queue <node> x;
				x = q2[i].front();
				while (!x.empty()) q[i].push(x.front()), x.pop();
//				cout << q[i].size();
				q2[i].pop();
			}
		}
//		for (int i = 0; i < N; i++)
//		{
//			for (int l = 1; l <= (ll)q[i].size(); l++)
//			{
//				node x;
//				x = q[i].front(), q[i].pop();
//				printf("%d %d %d\n", x.l, i, x.id);
//				q[i].push(x);
//			}
//		}
		// dp[i][j] Ç°iÂÖ£¬½áÎ²Îªj 
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 1; j < N; j++)
			{
				if (i == 1)
				{
					for (int l = 1; l <= (ll)q[j].size(); l++)
					{
						node x;
						x = q[j].front(), q[j].pop();
						dp[i][j] |= (x.l == 1);
						q[j].push(x);
					}
					continue;
				}
				for (int l = 1; l <= (ll)q[j].size(); l++)
				{
					node x;
					x = q[j].front(), q[j].pop();
//					cout << x.l<<endl;
					if (vis[x.l] > 1) dp[i][j] |= dp[i - 1][x.l];//, cout << i << " " << j << endl;
					q[j].push(x);
				}
			}
		}
		while (qs--)
		{
			ll r, c;
			scanf("%d%d", &r, &c);
			puts(dp[r][c] ? "1" : "0");
		}
	}
	return 0;
}
