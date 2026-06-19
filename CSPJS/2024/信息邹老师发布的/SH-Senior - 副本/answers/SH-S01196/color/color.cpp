#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
bool vis[Maxn];


int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		ll ans = 0;
		for (int i = 0; i < (1 << n); i++)
		{
			memset(vis, 0, sizeof(vis));
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					vis[j + 1] = true;
			
			ll res = 0;
			for (int j = 1; j <= n; j++)
				for (int k = j - 1; k >= 1; k--)
					if (vis[k] == vis[j])
					{
						res += (a[k] == a[j] ? a[j] : 0);
						break;
					}
			ans = max(ans, res);
		}
		cout << ans << '\n'; 
	}
	
	return 0;
}

