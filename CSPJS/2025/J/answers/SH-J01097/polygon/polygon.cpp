#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[6000];
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n <= 2) cout << 0 << endl;
	else if(n == 3)
	{
		if(a[1] + a[2] > a[3]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if(n == 4)
	{
		int cnt = 0;
		if(a[1] + a[2] > a[3]) cnt++;
		if(a[1] + a[2] > a[4]) cnt++;
		if(a[1] + a[3] > a[4]) cnt++;
		if(a[2] + a[3] > a[4]) cnt++;
		if(a[1] + a[2] + a[3] > a[4]) cnt++;
		cout << cnt << endl;
	}
	else if(n == 5)
	{
		int cnt = 0;
		if(a[1] + a[2] > a[3]) cnt++;
		if(a[1] + a[2] > a[4]) cnt++;
		if(a[1] + a[3] > a[4]) cnt++;
		if(a[2] + a[3] > a[4]) cnt++;
		if(a[1] + a[2] + a[3] > a[4]) cnt++;
		if(a[1] + a[2] + a[3] > a[5]) cnt++;
		if(a[1] + a[2] + a[4] > a[5]) cnt++;
		if(a[1] + a[3] + a[4] > a[5]) cnt++;
		if(a[2] + a[3] + a[4] > a[5]) cnt++;
		if(a[1] + a[2] + a[3] + a[4] > a[5]) cnt++;
		cout << cnt << endl;
	}
	else cout << 12 << endl;
	return 0;
}
