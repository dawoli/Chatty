#include <bits/stdc++.h>
using namespace std;

char s;
int num[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	int i = 1;
	while(cin >> s)
	{
		if (s >= '0' && s <= '9')
		{
			num[s-'0']++;
		}
		i++;
	}
	if (num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0 && num[5] == 0 && num[6] == 0 && num[7] == 0 && num[8] == 0 && num[9] == 0)
	{
		cout << "0";
		return 0;
	}
	for (int j = 9; j >= 0; --j)
	{
		for (int k = 1; k <= num[j]; ++k)
		{
			cout << j;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
