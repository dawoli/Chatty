#include<bits/stdc++.h>
using namespace std;
int T, n, a[100005], b[100005], c[100005],ans;
int main()
{
	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		ans = 0;
		int cnta = 0, cntb = 0, cntc = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			int maxn = max(a[i], max(b[i], c[i]));
			ans += maxn;
		}
		
	}
	cout <<ans;
	return 0;
}
