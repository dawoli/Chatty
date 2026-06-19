#include <bits/stdc++.h>
using namespace std;
int n, q;
pair<string, string> s[200005];
pair<int, int> differ(string s1, string s2)
{
	int l = -1, r = -1;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i] && l == -1)
		{
			l = i;
			break;
		}
	}
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (s1[i] != s2[i] && r == -1)
		{
			r = i;
			break;
		}
	}
	return {l, r};
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		cin >> s[i].first >> s[i].second;
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.length() != t2.length())
		{
			printf("0\n");
			continue;
		}
		int l, r;
		l = differ(t1, t2).first;
		r = differ(t1, t2).second;
		string dstr1, dstr2;
		dstr1 = t1.substr(l, r - l + 1);
		dstr2 = t2.substr(l, r - l + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			bool flag = 0;
			for (int j = 0; j + dstr1.length() <= s[i].first.length(); j++)
			{
				if (s[i].first.substr(j, dstr1.length()) == dstr1 && s[i].second.substr(j, dstr2.length()) == dstr2)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
