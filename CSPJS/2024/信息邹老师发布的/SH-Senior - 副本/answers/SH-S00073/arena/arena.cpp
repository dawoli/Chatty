#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct Node{
	int id, x;
} A[N];
int n, m, a[N], c[N], b[5];
string s[N];

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i];
	}
	int k = 0, mul = 1;
	while (mul < n)
	{
		mul *= 2;
		k++;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> s[i];
	}
	int t;
	cin >> t;
	while (t--)
	{
		cin >> b[0] >> b[1] >> b[2] >> b[3];
		for (int i = 1; i <= n; i++)
		{
			A[i].x = a[i] ^ b[i % 4];
			A[i].id = i;
		}
		for (int i = n + 1; i <= mul; i++)
		{
			A[i].x = 2e9;
			A[i].id = i;
		}
		long long sum = 0;
		for (int f = 1; f <= m; f++)
		{
			queue<Node> q; 
			int h = pow(2, ceil(log2(c[f])));
			for (int i = 1; i <= min(h, n); i++)
			{
				q.push(A[i]);
			}
			long long ans = 0;
			for (int i = n + 1; i <= min(h, mul); i++)
			{
				ans += i;
			}
			int r = c[f] - 1; 
			for (int i = 1; i <= r; i++)
			{
				for (int j = 0; j < pow(2, r - i); j++)
				{
					Node x = q.front();
					q.pop();
					Node y = q.front();
					q.pop();
					if (s[i][j] == '0')
					{
						if (x.x >= i) q.push(x);
						else q.push(y);
					}
					else
					{
						if (y.x >= i) q.push(y);
						else q.push(x);
					}
				}
			}
			ans += q.front().id;
			sum = sum ^ (1ll * f * ans);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
