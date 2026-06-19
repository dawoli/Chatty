#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	int a[5005];
	int maxn = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] > maxn) maxn = a[i];
	}
	if( n == 3 )
	{
		if(a[0] + a[1] + a[2] > maxn * 2)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			for(int k = j; k < n; k++)
			{
				int maxn = max(a[k], max(a[j], a[i]));
				if(a[i] + a[j] + a[k] > maxn * 2) ans++;
			}
		}
	}	
	
	
	
	cout << ans;
	return 0; 
}
