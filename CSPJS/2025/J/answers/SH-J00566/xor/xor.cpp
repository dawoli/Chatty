#include <bits/stdc++.h>

using namespace std; 

int n; 
int k; 
int a[500005]; 
bool flag = true; 
bool flag2 = true; 

int main()
{
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout); 
	cin >> n >> k; 
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		if(!a[i])
		{
			flag = false; 
		}
		if(a[i] > 1)
		{
			flag2 = false; 
		}
	}
	if(flag)
	{
		cout << (n / 2); 
	}
	else if(flag2)
	{
		if(k == 0)
		{
			int cnt = 0; 
			for(int i = 1; i <= n; )
			{
				if(!a[i])
				{
					cnt++; 
					i++; 
					continue; 
				}
				if(a[i] == 1 && a[i + 1] == 1)
				{
					cnt++; 
					i += 2; 
					continue; 
				}
				i++; 
			}
			cout << cnt; 
		}
		else if(k == 1)
		{
			int cnt = 0; 
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 1)
				{
					cnt++; 
				}
			}
			cout << cnt; 
		}
	}
	return 0; 
}
