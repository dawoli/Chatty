#include<bits/stdc++.h>
using namespace std ; 
int T , n ; 
const int N = 1e5 + 10 ; 
int mar ; 
bool g[N] ; 
int a[N] ; 
void dfs(int x,int rf) {
	if(x == n + 1 ) { mar = max(mar , rf) ; return ; 
	}
	int pos = x ; 
	for(int i = x - 1 ; i >= 1 ; i-- ) if(g[i] == 0 ) { pos = i ; break ; }
	if(pos != x && a[pos] == a[x] ) {
		rf += a[pos] ;
	}
	dfs(x + 1 , rf) ;
	if(pos != x && a[pos] == a[x] ) {
		rf -= a[pos] ;
	}
	for(int i = x - 1 ; i >= 1 ; i-- ) if(g[i] == 1 ) { pos = i ; break ; }	
	if(pos != x && a[pos] == a[x]) rf += a[pos] ; 
	g[x] = 1 ; 
	dfs(x + 1 , rf) ; 
	if(pos != x && a[pos] == a[x]) rf -= a[pos] ; 
	g[x] = 0 ; 
}
int brufe() {
	memset(g , 0 , sizeof(g)) ;
	mar = -INT_MAX ; 
	dfs(1,0) ;
	return mar ; 
}

int main() {
	freopen("color.in","r",stdin) ; 
	freopen("color.out","w",stdout) ;  
	cin >> T ; 
	while(T--) {
		cin >> n ; 
		for ( int i = 1 ; i <= n ; ++i) cin >> a[i] ; 
		cout << brufe() << endl ; 
	}
	return 0 ; 
} 
