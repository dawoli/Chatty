#include "bits/stdc++.h"
using namespace std ;
int n, a[100005], ans ;
bool cmp(int a, int b) {return a < b ;}
priority_queue<int, vector<int>, greater<int> > q ;
int main()
{
	freopen("duel.in", "r", stdin) ;
	freopen("duel.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
	sort(a + 1, a + n + 1, cmp) ;
	for(int i = 1 ; i <= n ; ++i)
	{
		q.push(a[i]), ++ans ;
		if(q.top() < a[i]) --ans, q.pop() ;
	}
	cout << ans << endl ;
	return 0 ;
}
// AC AC AC AC AC AC AC AC AC AC AC AC
//   STO OTZ sto orz STO OTZ sto orz
// AC AC AC AC AC AC AC AC AC AC AC AC
//          My dear CCF plz
