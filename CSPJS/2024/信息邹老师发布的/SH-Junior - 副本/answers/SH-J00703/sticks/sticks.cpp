#include <bits/stdc++.h>
using namespace std;

string f(int n)
{
	switch (n)
	{
		case 2:
			return "1";
		case 3:
			return "7";
		case 4:
			return "4";
		case 5:
			return "2";
		case 6:
			return "6";
		case 7:
			return "8";
		case 8:
			return "10";
		case 9:
			return "18";
		case 10:
			return "22";
		case 11:
			return "20";
		case 12:
			return "28";
		case 13:
			return "68";
		case 14:
			return "88";
	}
}
 
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	for (int x = 0; x < T; x++)
	{
		int n;
		cin >> n;
		if (n < 2) // check if not available 
		{
			cout << -1 << endl;
			continue;
		}
		int eight_count = max((n-8)/7, 0); // 1
		cout << f(n-eight_count * 7);
		for (int i = 0; i < eight_count; i++)
		{
			cout << "8";
		}
		cout << endl;
	}
	return 0;
}


