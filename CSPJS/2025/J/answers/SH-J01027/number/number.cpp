#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int m = 0;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[++m] = (int)s[i] - 48;
		}
	}
	sort(a + 1, a + m + 1);
	if(a[m] == 0)
	{
		cout << "0" << "\n";
	}
	else
	{
		for(int i = m; i >= 1; i--)
		{
			cout << a[i];
		}
		cout << "\n";
	}
	return 0;
}
