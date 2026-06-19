#include "bits/stdc++.h"
using namespace std ;
int T, n, a[200005], f[1000006], ans ;
vector<int> li ;
void dfs(int s, vector<int> book)
{
	if(s > n)
	{
		int cnt[2][22], res = 0 ;
		memset(cnt, 0, 20) ;
		for(int i = 0 ; i < book.size() ; ++i)
		{
			if(cnt[book[i]][a[i]] == 1) res += a[i], cnt[book[i]][a[i]] = 0 ;
			else memset(cnt[book[i]], 0, sizeof(cnt[book[i]])) ;
			cnt[book[i]][a[i]] = 1 ;
		}
		ans = max(ans, res) ;
		return ;
	}
	book.push_back(0) ;
	dfs(s + 1, book) ;
	book.pop_back() ;
	book.push_back(1) ;
	dfs(s + 1, book) ;
}
int main()
{
	freopen("color.in", "r", stdin) ;
	freopen("color.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> T ;
	for(int t = 1 ; t <= T ; ++t)
	{
		memset(f, 0, sizeof(f)) ;
		ans = 0 ;
		cin >> n ;
		for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
		if(n <= 15)
		{
			dfs(0, li) ;
			cout << ans << endl ;
			continue ;
		}
		for(int i = 1 ; i <= n ; ++i)
		{
			if(f[a[i]]) ans += a[i], f[a[i]] = 0 ;
			else f[a[i]] = 1 ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}
// AC AC AC AC AC AC AC AC AC AC AC AC
//   STO OTZ sto orz STO OTZ sto orz
// AC AC AC AC AC AC AC AC AC AC AC AC
//          My dear CCF plz
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
*/
