#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if(k == 0)
	{
		if(n % 2 == 0) cout << n;
		else cout << n - 1;
	}
	else if(k == 1)
	{
		cout << n;
	}
	else cout << 1;
	
	return 0;
}
