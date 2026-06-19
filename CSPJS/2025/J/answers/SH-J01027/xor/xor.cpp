#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	bool f = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			f = 1;
		}
	}
	if(k == 0 && !f)
	{
		cout << n / 2 << "\n";	
	}
	else
	{
		int cnt = 0;
		for(int i = 2; i <= n; i++)
		{
			if(a[i] == k)
			{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
 } 
