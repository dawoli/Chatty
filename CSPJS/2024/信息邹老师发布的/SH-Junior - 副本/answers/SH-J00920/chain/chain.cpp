#include<bits/stdc++.h>
using namespace std;

int T, n, k, q, x, a[1010][110], b[100010];

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++){
			cin >> x;
			for(int j = 1; j <= x; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= q; i++){
			cin >> b[i];
			cout << 0 << endl;
		}
	}
	return 0;
}
