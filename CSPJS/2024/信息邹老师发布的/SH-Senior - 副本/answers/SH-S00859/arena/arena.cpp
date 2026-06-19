#include <bits/stdc++.h>
using namespace std ; 
int n , m  ; 
const int N = 1e5 + 10 ;
int a1[N] ;
int a[N] , b[N]; 
int c[N] ; 
int ans[N] ; 
int K , T ; 
vector <int> q[30] ; 
int get_winner(int P) { //2^P
	int len = (1<<P) ; 
	int res[N] ,tem[N] , size = len , round = 1 ; 
	for (int i = 1 ; i <= len ; ++i) res[i] = i ; 
	while(size > 1 ) {
		int news = 0 ; 
		for ( int j = 1 ; j <= size ; j += 2) {
			if(q[round][(j-1)/2]==0) {
				if(a[res[j]]>=round) tem[++news]=res[j] ; 
				else tem[++news] = res[j + 1 ] ; 
			}
			else {
				if(a[res[j + 1]]>=round) tem[++news]=res[j + 1] ; 
				else tem[++news] = res[j] ; 
			}
		}
		size = news ; 
		for ( int i = 1 ; i <= size ; i++ ) res[i] = tem[i] ; 
		round++ ; 
	}
	return res[1] ; 
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout) ; 
	cin >> n >> m ; 
	double g = log2(n) ; 
	if(g == int(g)) K = g ; 
	else K = int(g) + 1 ; 
	for ( int i = 1 ; i <= n ; ++i) cin >> a1[i] ; 
	for ( int i = 1 ; i <= m ; ++i) cin >> c[i] ;
	for ( int i = 1 ; i <= K; ++i) {
		string f ; 
		cin >> f ; 
		for ( int j = 0 ; j < f.size() ; j++) q[i].push_back(f[j]-'0') ; 
	}
//	for ( int i = 1 ; i <= K ; ++i , cout << endl ) {
//		for (int j = 0 ; j < (1<<(K-i)) ; j++) cout << q[i][j] <<' ' ;
//	}
	cin >> T ;
	for ( int r = 1 ; r <= T ; r++) {
		memset(a , 0 , sizeof(a)) ; 
		int x[5] ; 
		cin >> x[0] >> x[1] >> x[2] >> x[3] ; 
		for ( int i = 1 ; i <= n ; ++i ) b[i] = a1[i] ^ (x[i % 4]) ;
	//	cout << "a[i]:" << endl ; 
	//	for ( int i = 1 ; i <= n ;++i ) cout << a[i] << ' ' ; cout << endl ; 
		for (int i = 1 ; i <= n ; ++i ) {
			a[i] = b[i] ; 
			double gg = log2(i) ; 
			if(gg == int(gg)) ans[i] = get_winner(int(gg)) ;
			else {
				int K = int(gg) + 1 ; 
				int hk[N] ; 
				memset(hk , 0 , sizeof(hk)) ; 
				int NN = (1 << K) ; 
		//		cout << "*" << i <<' ' << NN << endl ; 
				for ( int t = 0 ; t < 1<<(NN-i) ; t++ ) {
					for ( int j = i + 1 ; j <= NN ; j++ ) {
						if(t>>(NN-j) & 1 ) a[j] = INT_MAX ; 
			//			cout << a[j] << endl ; 
					}
			//		cout << "@" << get_winner(K) << endl ; 
					hk[get_winner(K)]++ ; 
					for ( int j = n + 1 ; j <= NN ; j++ ) {
						a[j] = 0 ;
					}					 
				}
				for(int j = 1 ; j <= (1<<K) ; j++ ) if(hk[j]) ans[i]+=j ; 
			} 
			int Rf = ans[1] ; 
			for (int u = 2 ; u <= )
		}
	}
	return 0 ;
}
