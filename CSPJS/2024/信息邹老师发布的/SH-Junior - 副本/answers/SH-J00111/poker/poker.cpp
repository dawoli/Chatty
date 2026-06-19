#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int a, ans;
	string p[53];
	cin >> a;
	ans = 52 - a;
	for(int i = 0;i < a;i++)
	{
		cin >> p[i];
		if(i)
		{
			for(int j = 0;j < i;j++)
			{
				if(p[j] == p[i])
				{
					ans++;
					break;
				}
			}
		}
		
	}
	cout << ans;
	return 0;
} 
