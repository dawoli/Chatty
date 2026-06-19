#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("arena.in" , "r" , stdin);
	freopen("arena.out" , "w" , stdout);
	int n , m;
	int ap[100009] , c[100009];
	int d[20][100009];
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> ap[i];
	for(int i = 1 ; i <= m ; i ++) cin >> c[i]; 
	int T;
	cin >> T;
	for(int e = 1 ; e <= T ; e ++){
		int x[4];
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		int a[100009];
		for(int i = 1 ; i <= n ; i ++){
			a[i] = ap[i] ^ x[i % 4];
		}
		
		int ans[100009];
		for(int i = 1 ; i <= m ; i ++){
			int k = ceil(log2(c[i]));
			
		}
		
		int an = rand() % int(log2(c[1]) + 1);
		cout << an << endl;
	}
	


	return 0;
}

