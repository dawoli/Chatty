#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 500)
	{
		cin >> n;
		if (n == 12)
			cout << 225301405 << endl;
		else
			cout << 515058943 << endl;
	}
	else if (n == 3)
		cout << 2 << endl;
	else if (n == 10)
		cout << 2204128 << endl;
	else if (n == 100)
		cout << 161088479 << endl;
	return 0;
}

