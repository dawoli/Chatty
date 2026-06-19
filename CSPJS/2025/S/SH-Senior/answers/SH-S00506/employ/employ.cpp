#include <bits/stdc++.h>
using namespace std;
int a[505];
struct employeee
{
	int patiencee, id;
	friend bool operator<(employeee a, employeee b)
	{
		return a.id < b.id;
	}
} t[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		a[i + 1] = s[i] - '0';
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i].patiencee;
		t[i].id = i;
	}
	sort(t + 1, t + n + 1);
	int ans = 0;
	do
	{
		int badp = 0, goodp = 0;
		for (int dayt = 1; dayt <= n; dayt++)
		{
			if (badp >= t[dayt].patiencee)
				badp++;
			else if (a[dayt] == 0)
				badp++;
			else
				goodp++;
		}
		if (goodp >= m)
			ans++;
	} while (next_permutation(t + 1, t + n + 1));
	cout << ans;
	return 0;
} 
