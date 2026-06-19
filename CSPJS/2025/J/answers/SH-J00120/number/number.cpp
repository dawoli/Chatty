# include <iostream>
using namespace std;

int dig[15] = {};
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i <= s.size(); i ++)
	{
		if (s[i] <= '9' and s[i] >= '0')
		{
			dig[int(s[i] - '0')] ++;
		}
	}
	for (int i = 9; i >= 0; i --)
	{
		if (dig[i] > 0)
		{
			for (int j = dig[i]; j >= 1; j --)
			{
				cout << i;
			}
		}
	}
	return 0;
}
