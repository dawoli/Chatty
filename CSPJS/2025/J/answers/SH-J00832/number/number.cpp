#include <iostream>
using namespace std;

int cnt[20];
string s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= cnt[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
