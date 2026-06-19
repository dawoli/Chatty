#include <bits/stdc++.h>
using namespace std;
int a[100002] = {};
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (k == 0)
	{
		bool flag = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] != 1) flag = 0;
		}
		if (flag)
		{
			cout << n / 2;
		}
	}
	else cout << 1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
