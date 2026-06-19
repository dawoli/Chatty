// T3 replace
// about 25 pts
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n, q;
string s1[MAXN], s2[MAXN];
string t1, t2;
int lent;
int first_diff;
int last_diff;

int solve(string s1, string s2)
{
	int lens = s1.length();
	
	int cnt = 0;
	for (int i = 0; i + lens - 1 < lent; i++)
	{
		if (i > first_diff)
			break;
		if (i + lens - 1 < last_diff)
			continue;
		bool ok = true;
		for (int j = 0; j < lens; j++)
		{
			if (s1[j] != t1[i + j])
			{
				ok = false;
				break;
			}
		}
		string new_str = "";
		if (ok)
		{
			for (int j = 0; j < i; j++)
				new_str += t1[j];
			new_str += s2;
			for (int j = i + lens; j < lent; j++)
				new_str += t1[j];
			cnt += (new_str == t2);
		}
	}
	return cnt;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	while (q--)
	{
		cin >> t1 >> t2;
		
		lent = t1.length();
		if (lent != (int)t2.length())
		{
			cout << "0\n";
			continue;
		}
		
		first_diff = last_diff = -1;
		for (int i = 0; i < lent; i++)
		{
			if (t1[i] != t2[i])
			{
				if (first_diff == -1)
					first_diff = i;
				last_diff = i;
			}
		}
		
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += solve(s1[i], s2[i]);
		}
		cout << ans << "\n";
	}
}
