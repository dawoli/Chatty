#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool b[155][155];
char s, t;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s >> t;
		if (b[s][t] == 0)
		{
			b[s][t] = 1;
			ans++;
		}
	}
	cout << (52 - ans);
}
