#include<bits/stdc++.h>
using namespace std ;
int t , n , m , k ;
int x , y , d ;
int nx , ny , nd ;
char s[2000][2000] ;
int vis[2000][2000] ;

int main(){
	
	freopen("explore.in" , "r" , stdin) ;
	freopen("explore.out" , "w" , stdout) ;
	cin >> t ;
	for(int l = 1 ; l <= t ; l++){
		memset(vis , 0 , sizeof(vis)) ;
		cin >> n >> m >> k ;
		cin >> x >> y >> d ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> s[i][j] ;
			}
		}
		int cnt = 0 ;
		for(int q = 1 ; q <= k ; q++){
			if(d == 0){
				nx = x ;
				ny = y + 1 ;
			}else if(d == 1){
				nx = x + 1 ;
				ny = y ;
			}else if(d == 2){
				nx = x ;
				ny = y - 1 ;
			}else if(d == 3){
				nx = x - 1 ;
				ny = y ;
			}
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && s[nx][ny] == '.'){
				x = nx ;
				y = ny ;
			}else{
				d = (d+1) % 4 ;
			}
			if(vis[x][y] == 0){
				vis[x][y] = 1 ;
				cnt++ ;
			}
		}
		cout << cnt << endl ;
	}
	
	return 0 ;
} 
