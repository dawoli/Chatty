#include "bits/stdc++.h"
#define int long long
#define For(i, l, r) for(int i = (l) ; i <= (r) ; ++i)
using namespace std ;
const int N = 200005, M = 200005, L = 5000006 ;
int n, q, ans, preS[N], preT[N] ;
string s[N][2], t[N][2] ;
signed main()
{
	freopen("replace.in", "r", stdin) ;
	freopen("replace.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> q ;
	For(i, 1, n)
	{
		cin >> s[i][0] >> s[i][1] ;
		For(j, 0, s[i][0].size() - 1) if(s[i][0][j] != s[i][1][j]) preS[i]++ ;
	}
	For(i, 1, q)
	{
		ans = 0 ;
		cin >> t[i][0] >> t[i][1] ;
		if(t[i][0].size() != t[i][1].size())
		{
			cout << 0 << "\n" ;
			continue ;
		}
		For(j, 0, t[i][0].size() - 1) if(t[i][0][j] != t[i][1][j]) preT[i]++ ;
		For(j, 1, n)
		{
			if(preS[j] != preT[i]) continue ;
			int tmp1 = t[i][0].find(s[j][0]), tmp2 = t[i][1].find(s[j][1]) ;
			if(tmp1 == tmp2 && tmp1 <= t[i][0].size()) ans++ ;
		}
		cout << ans << "\n" ;
	}
	return 0 ;
}
