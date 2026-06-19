#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	int cnt = 0, ans1 = 9999999;
	for(int i = 1; i <= m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		cnt += w;
	}
	
	for(int i = 1; i <= k; i ++) 
	{
		int ans = 0;
		for(int j = 1; j <= n + 1; j ++)
		{
			int k;
			cin >> k; 
			ans += (j != 1? k: 0);
		}
		ans1 = min(ans1, ans);
	}
		
	
	cout << min(ans1, cnt);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
