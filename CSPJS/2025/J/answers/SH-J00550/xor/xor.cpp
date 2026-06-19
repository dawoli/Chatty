#include <bits/stdc++.h> // 期望得分：100 
using namespace std ;

int n, k ;
int mp[500005] ;
int qx[500005] ;
int sum_xor()
{
	int sum = mp[1] ;
	qx[1] = sum ;
	for (int i = 2; i <= n; i++)
	{
		qx[i] = sum = sum ^ mp[i] ;
	}
	return sum ;
}
int ans = 0 ;
int lr, ll ;
int xor_v ;
int main()
{
	freopen("xor.in", "r", stdin) ;
	freopen("xor.out", "w", stdout) ;
	cin >> n >> k ;
	for (int i = 1; i <= n; i++)
	{
		cin >> mp[i] ;
	}
	sum_xor() ;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i <= lr && j > lr)
			{
				break ;
			}
			xor_v = qx[i - 1] xor qx[j] ;
			if (xor_v == k)
			{
				if (j <= lr && i > ll)
				{
					lr = j ;
					ll = i ;
				}
				else if (i > lr)
				{
					ans++ ;
					lr = j ;
					ll = i ;
					break ;
				}
			}
		}
	}
	cout << ans ;
	return 0 ;
}
