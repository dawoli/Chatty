#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int q = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[++q] = s[i] - '0';
		}
	}
	sort(a + 1, a + q + 1);
	for(int i = q; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
