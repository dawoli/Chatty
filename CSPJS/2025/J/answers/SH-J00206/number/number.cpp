# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll cnt[10];
string s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size(), s = " " + s;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= cnt[i]; j++) printf("%d", i);
	}
	printf("\n");
	return 0;
}
