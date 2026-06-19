#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[10005];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n *m; i++) cin >> arr[i];
	
	ll sco = arr[1];
	
	sort(arr + 1, arr + n * m +1);
	
	for (int i = n * m; i >= 1; i--)
	{
		if (arr[i] == sco)
		{
			ll t = n *m - i + 1;
			ll c = (t + n - 1) / n;
			ll r = (t % m) == 0 ? m : (t % m);
			if (c % 2 == 1) cout << c << " " <<r <<endl;
			else cout << c << " " << m - r + 1 << endl; 
			return 0;
		}
	}
	
	return 0;
} 
