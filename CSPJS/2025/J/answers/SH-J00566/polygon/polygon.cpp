#include <bits/stdc++.h>

using namespace std; 

int n; 
int a[5005]; 
bool flag = true; 
string b[1250000]; 
int c[12500000]; 

int main()
{
	freopen("polygon.in", "r", stdin); 
	freopen("polygon.out", "w", stdout); 
	cin >> n; 
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		if(a[i] > 1)
		{
			flag = false; 
		}
	}
	if(flag)
	{
		cout << n * (n - 1) * (n - 2) / 3; 
	}
	else
	{
		int cnt = 0; 
		for(int i = 1; i <= n; i++)
		{
			b[++cnt] += (i + '0'); 
			c[cnt] = a[i]; 
			int cn = cnt; 
			for(int j = 1; j < cn; j++)
			{
				b[++cnt] += b[j]; 
				b[cnt] += (i + '0'); 
				c[cnt] = c[j] + a[i]; 
			}
		}
		int ans = 0; 
		for(int i = 1; i <= cnt; i++)
		{
			
			int bl = b[i].length(); 
			if(bl > 2)
			{
				if(a[(b[i][bl - 1] - '0')] * 2 < c[i])
				{
					ans++; 
				}
			}
		}
		cout << ans; 
	}
	return 0; 
}
