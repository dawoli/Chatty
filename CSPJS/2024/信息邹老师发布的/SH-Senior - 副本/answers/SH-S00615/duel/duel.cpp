#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, ans, cnt;
int a[N]; 

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	ans = n, cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > a[cnt])
		{
			ans--;
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}
