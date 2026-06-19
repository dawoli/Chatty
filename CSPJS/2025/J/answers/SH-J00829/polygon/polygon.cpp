#include<bits/stdc++.h>
using namespace std;
int s[10009], n;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] < s[i + 1])
		{
			int x = s[i];
			s[i] = s[i + 1];
			s[i + 1] = x;
		}
	}
	if (n >= 3)
	{
		if (s[0] + s[1] + s[2] > s[0] * 2)
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
	return 0;
}
