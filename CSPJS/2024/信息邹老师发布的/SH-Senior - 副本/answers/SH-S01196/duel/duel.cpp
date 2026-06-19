#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];


int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int cnt = 0, ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == a[i - 1])
			cnt++;
		else
			cnt = 0;
		
		if (i - 1 - ans - cnt > 0)
			ans++;
	}
	cout << n - ans << '\n';
	
	return 0;
}

