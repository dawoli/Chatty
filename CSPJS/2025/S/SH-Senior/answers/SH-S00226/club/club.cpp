#include <bits/stdc++.h>
using namespace std ;
const int MAX = 2000 ;
int main()
{
	freopen("club.in" , "r" ,stdin) ;
	freopen("club.out" , "w" ,stdout) ;
	int t = 0;
	cin >> t ;
	for(int i = 1; i <= t ; i++)
	{
		int n ;
		cin >> n ;
		int s[MAX][5] ;
		for(int j = 1 ; j <= n ; j++) cin >> s[j][1] >> s[j][2] >> s[j][3] ; 
		int ans1[MAX] ;
		for(int j = 1 ; j <= n ; j++) ans1[j] = 0 ;
 		int ans = 0 ;
 		int num[5] ;
 		bool flag[MAX] ;
 		int cs[MAX] ;
 		int dp[MAX][5] ;
 		bool flag2 = true ;
 		int jy[MAX][MAX] ;
 		int x = 0;
 		for(int j = 1 ; j <= n ; j++) 
		{
			if(s[j][2] != 0 || s[j][3]!= 0)
			{
				flag2 = false ;
			}
		}
 		for(int j = 1 ; j <= n ; j++) flag[MAX] = true ;
		if(n == 2) 
		{
			for(int j = 1 ; j <= n ; j++)
			{
				for(int k = 1 ; k <= 3 ; k++)
				{
					ans1[j] = max (ans1[j] , s[j][k]) ;
				}
				ans += ans1[j] ;
			}
		}
		else if(flag2)
		{
			for(int j = 1 ; j <= n ; j++) ans += s[j][1] ;
		}
		else
		{
			for(int j = 1 ; j <= n ; j++)
			{
				for(int k = 1 ; k <= 3 ; k++)
				{
					ans1[j] = max (ans1[j] , s[j][k]) ;
					if(ans1[j] == s[j][k]&&flag[j]) 
					{
						num[k]++ ;
						flag[j] = false ;
					}
				}
				if(num[1]<=0.5*n&&num[2]<=0.5*n&&num[3]<=0.5*n) ans += ans1[j] ;
				else
				{
					while(num[1]>0.5*n||num[2]>0.5*n||num[3]>0.5*n)
					{
						if(num[1]>0.5*n)
						{
							num[1]-- ;
							if(s[j][2] > s[j][3]&&num[2]+1<=0.5*n) ans += s[j][2] ;
							else ans += s[j][3] ; 
						}
						if(num[2]>0.5*n)
						{
							num[2]-- ;
							if(s[j][1] > s[j][3]&&num[1]+1<=0.5*n) ans += s[j][1] ;
							else ans += s[j][3] ; 
						}
						if(num[3]>0.5*n)
						{
							num[3]-- ;
							if(s[j][2] > s[j][1]&&num[2]+1<=0.5*n) ans += s[j][2] ;
							else ans += s[j][1] ; 
						}
					}
				}
			}
			

		}
		cout << ans ;
	}
	return 0 ;
} 
