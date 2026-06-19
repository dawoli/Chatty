#include "bits/stdc++.h"
#define int long long
#define For(i, l, r) for(int i = (l) ; i <= (r) ; ++i)
using namespace std ;
const int N = 10004, M = 1000006, K = 13 ;
struct Node {int u, v, w ;} ;
int n, m, k, c[K], a[K][N], ans, res ;
int u, v, w ;
bool tagA ;
Node road[M << 1] ;
int f[N << 1] ;
inline bool cmp(Node x, Node y) {return x.w < y.w ;}
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]) ;}
inline void merge(int x, int y) {f[find(y)] = x ;}
signed main()
{
	freopen("road.in", "r", stdin) ;
	freopen("road.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m >> k ;
	For(i, 1, n + k) f[i] = i ;
	For(i, 1, m) cin >> u >> v >> w, road[i] = {u, v, w} ;
	For(i, 1, k)
	{
		cin >> c[i] ; tagA = (tagA || c[i]) ;
		For(j, 1, n) cin >> a[i][j] ;
	}
	int cnt = m, p = 0 ;
	For(i, 1, k) For(j, 1, n) road[++cnt] = {n + i, j, a[i][j]} ;
	--cnt ;
	sort(road + 1, road + cnt + 1, cmp) ;
	For(i, 1, cnt)
	{
		Node tmp = road[i] ;
		if(find(tmp.u) != find(tmp.v))
		{
			merge(tmp.u, tmp.v), ans += tmp.w ;
			res++ ;
		}
	}
	cout << ans ;
	return 0 ;
}
/*
GIMME S 1= PLZZZZZZZZZZZZZZZZZZZZZZZZ
================================================================
             #####          #####         #######
           ##     #       ##     #        #
          #              #                #
          #              #                ######
rtO        ##     #       ##     #        #         Orz
             #####          #####         #
================================================================
*/
