#include "bits/stdc++.h"
using namespace std ;
int T, n, m, k, ans ;
int x, y, d, mp[1003][1003], f[1003][1003] ;
int pj[4] = {1, 0, -1, 0} ;
int pi[4] = {0, 1, 0, -1} ;
char c ;
int main()
{
	freopen("explore.in", "r", stdin) ;
	freopen("explore.out", "w", stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; cout.tie(0) ;
	cin >> T ;
	for(int t = 1 ; t <= T ; ++t)
	{
		ans = 0 ;
		memset(f, 0, sizeof(f)) ;
		cin >> n >> m >> k >> x >> y >> d ;
		for(int i = 0 ; i <= n + 1 ; ++i)
		{
			for(int j = 0 ; j <= m + 1 ; ++j)
			{
				if(j == 0 || i == 0 || i == n + 1 || j == m + 1)
				{
					mp[i][j] = 1 ;
					continue ;
				}
				cin >> c ;
				if(c == '.') mp[i][j] = 0 ;
				else mp[i][j] = 1 ;
			}
		}
		f[x][y] = 1 ;
		for(int i = 1 ; i <= k ; ++i)
		{
			if(mp[x + pi[d]][y + pj[d]])
			{
				d = (d + 1) % 4 ;
				continue ;
			}
			x += pi[d] ;
			y += pj[d] ;
			f[x][y] = 1 ;
		}
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= m ; ++j)
				ans += f[i][j] ;
		cout << ans << endl ;
	}
    return 0 ;
}
//AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC
//STO OTZ stO Orz STO OTZ stO Orz STO OTZ stO Orz
//AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC 
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
