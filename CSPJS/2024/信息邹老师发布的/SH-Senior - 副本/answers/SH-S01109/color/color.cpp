#include <bits/stdc++.h>
using namespace std;
int t, n, ans, s[200005], U[200005];
struct node
{
	int a, color;	
}A[200005];
void water(queue <int> p, int cnt)
{
	memset(U, 0, sizeof(U));
	int u = p.front(), sum = 0, maxm = -1;
	p.pop();
	queue <int> k[200005];
	while(!p.empty())
	{
		int e = p.front();
		p.pop();
		for (int i = u + 1; i < e; i++)
		{
			U[A[i].a]++;
			k[A[i].a].push(i);
			maxm = max(maxm, A[i].a);
		}
		for (int i = 1; i <= maxm; i++)
		{
			if(U[A[i].a] > 1)
			{
				sum += (A[i].a) * (U[A[i].a] - 1);
			}
		}
		if (sum > cnt)
		{
			int maxn = -1; 
			queue <int> q[200005];
			for (int i = 1; i <= n; i++)
			{
				q[A[i].a].push(i);
				s[A[i].a]++;
				maxn = max(maxn, A[i].a);
			}
			for (int i = maxn; i >= 1; i--)
			{
				if (s[i] > 1)
				{
					queue <int> y;
					if (A[q[i].front()].color != 0) A[q[i].front()].color = 1;
					y.push(q[i].front());
					int x = s[i] - 1;
					while (x--)
					{
						int v = q[i].front();
						y.push(v);
						q[i].pop();
						if (A[q[i].front()].color != 0) A[q[i].front()].color = A[v].color;
					}
					water(y, i);
				}
			}
		}
		else
		{
			for (int i = u + 1; i < e; i++)
			{
				A[i].color = 2;
			}
		}
		u = e;
	}
	return;
}
bool check(int cur)
{
	for (int i = cur - 1; i >= 1; i--)
	{
		if (A[i].color == A[cur].color && A[i].a == A[cur].a)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		int maxn = -1; 
		queue <int> q[200005];
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i].a;
			q[A[i].a].push(i);
			s[A[i].a]++;
			maxn = max(maxn, A[i].a);
		}
		for (int i = maxn; i >= 1; i--)
		{
			if (s[i]) 
			{
				queue <int> p;
				if (A[q[i].front()].color != 0) A[q[i].front()].color = 1;
				p.push(q[i].front());
				int x = s[i] - 1;
				while (x--)
				{
					int v = q[i].front();
					p.push(v);
					q[i].pop();
					if (A[q[i].front()].color != 0) A[q[i].front()].color = A[v].color;
				}
				water(p, i);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (check(i))
			{
				ans += A[i].a;
			}
			else
			{
				continue;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
