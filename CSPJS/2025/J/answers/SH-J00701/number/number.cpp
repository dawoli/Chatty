#include <bits/stdc++.h>
using namespace std;

int a[1000010];
//230138

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cur = 0, n = s.size() - 1;
	for (int i = 0; i <= n; i++)
	{
		if (s[i] <= '9' && s[i] >= '0')
		{
			cur++;
			a[cur] = (s[i] - '0');
		}
	}
	sort(a + 1, a + cur + 1);
	if (a[cur] == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = cur; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
