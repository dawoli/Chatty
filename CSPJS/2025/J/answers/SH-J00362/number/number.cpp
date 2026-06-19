#include <iostream>
using namespace std;

string s;
int a[12];

int main()
{
freopen("number.in", "r", stdin);
freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			a[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			cout << i;
		}
	}
fclose(stdin);
fclose(stdout);
	return 0;
}
