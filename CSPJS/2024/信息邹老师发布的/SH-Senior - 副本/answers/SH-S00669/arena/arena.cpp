#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
int a[100010], c[10010];
bool d[21][100010];

void solve()
{
	
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	int K = ceil(log2(n));
	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= 1 << (K - i); j++)
		{
			cin >> d[i][j];
		}
	}
	cin >> T;
    for (int i = 1; i <= T; i++)
    {
    	cin >> n;
    	for (int j = 1; j <= n; j++)
    		cin >> A[j];
    	
    	solve();
	}
	
    return 0;
}
