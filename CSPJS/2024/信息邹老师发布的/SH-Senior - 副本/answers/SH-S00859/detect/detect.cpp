#include <bits/stdc++.h>
using namespace std ; 
int T , n , m , l , v0 ; 
const int N = 1e5 + 10 ;
int d[N] , v[N] , a[N] , p[N] ;  
int lx[N];  
struct len {int a , b ; };
bool operator <(const len &x , const len &y) {
	if(x.b < y.b) return true ;
	if(x.b > y.b) return false ; 
	if(x.b == y.b && x.a < y.a ) return true ; 
	return false ;  
}
len g[N] , g1[N]; 
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout) ;
	scanf("%d" , &T) ; 
	while(T--) {
		scanf("%d %d %d %d" , &n , &m , &l , &v0) ; 
		int rlen = 0 ; 
		for ( int i = 1 ; i <= n ; ++i) scanf("%d %d %d", &d[i] , &v[i] , &a[i]) ; 
		for ( int i = 1 ; i <= m ; ++i) scanf("%d" , &p[i]) ; 
		for ( int i = 1 ; i <= n ; ++i ) {
			if(a[i] > 0 ) {
				if(v[i] == v0 ) { //正好没有超速 
					lx[i] = 1 ; //下一个 
				}
				else if(v[i] > v0) lx[i] = 0 ;
				else {
					double u = (v0 * v0 - v[i] * v[i]) * 1.0000 / (2 * a[i]) ; 
					lx[i] = int(u) + 1 ; 
				}
				lx[i] += d[i] ; 
				if(lx[i] <= l ) rlen++ , g[rlen].a = lx[i] , g[rlen].b = l ; 
			}
			else if(a[i] == 0 ) {
				if(v[i] > v0) {
					rlen++ , g[rlen].a = d[i] , g[rlen].b = l ; 
				}
			}
			else {
				if(v[i] > v0 ) {
					double u = (v[i] * v[i] - v0 * v0) * 1.0000 / (-2 * a[i]) ; 
					if(u == int(u)) lx[i] = int(u) - 1 ; 
					else lx[i] = int(u) ; 
					rlen++ , g[rlen].a = d[i] , g[rlen].b = min(l , lx[i] + d[i]) ;  										
				} 
			}
		}
		sort(g + 1 , g + rlen + 1) ; 
//		for ( int i = 1 ; i <= rlen ; ++i ) {
//			cout << g[i].a <<' ' << g[i].b << endl ; 
//		}
		int ans1 = 0 , ans2 = 0 ; 
		for ( int i = 1 ; i <= rlen ; ++i ) {
			int f = upper_bound(p + 1 , p + m + 1 , g[i].b ) - p - 1 ; 
			if(p[f] >= g[i].a) ans1++ , g1[ans1].a = g[i].a , g1[ans1].b = g[i].b ; 
		}
		ans2 ++ ; int rk = p[upper_bound(p + 1 , p + m + 1 , g1[1].b ) - p - 1] ;  
		for ( int i = 2 ; i <= ans1 ; ++i ) {
			if(g1[i].a > rk ) {
				ans2 ++ ; 
			int f = upper_bound(p + 1 , p + m + 1 , g1[i].b ) - p - 1 ;	
				rk = p[f] ; 
			}
		}
		if(ans1 == 0 ) printf("0 %d\n" , m) ; 
		else printf("%d %d\n" , ans1 , m - ans2 ) ; 	
	}
	return 0 ; 
} 
