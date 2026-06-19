#include <bits/stdc++.h>
using namespace std;
int maxn = 0;
int sum = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if(k > maxn) maxn = k;
		sum += k;
	}
	if (sum > maxn * 2) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
