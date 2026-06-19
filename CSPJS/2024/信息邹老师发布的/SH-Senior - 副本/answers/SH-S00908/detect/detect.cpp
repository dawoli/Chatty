#include<bits/stdc++.h>
using namespace std ;
int t , n , m , l , vv ;
struct car{
	int d , v , a ;
}c[100005] ;
int p[100005] ;
int main(){
	
	freopen("detect.in" , "r" , stdin) ;
	freopen("detect.out" , "w" , stdout) ;
	cin >> t ;
	for(int k = 1 ; k <= t ; k++){
		cin >> n >> m >> l >> vv ;
		int cnt = 0 ;
		int minn = 1e8 ;
		for(int i = 1 ; i <= n ; i++){
			cin >> c[i].d >> c[i].v >> c[i].a ;
		}
		int maxx = -1 ;
		for(int i = 1 ; i <= m ; i++){
			cin >> p[i] ;
			if(p[i] > maxx){
				maxx = p[i] ;
			}
		}
		for(int i = 1 ; i <= n ; i++){
			if(c[i].d <= maxx){
				if(c[i].v > vv){
					cnt++ ;
				}
			}
		}
		if(cnt == 0){
			cout << cnt << " " << m << endl ;
		}else{
			cout << cnt << " " << m-1 << endl ;
		}
	}
	
	
	return 0 ;
} 
