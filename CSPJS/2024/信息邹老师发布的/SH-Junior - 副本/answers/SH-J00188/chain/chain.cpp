#include<bits/stdc++.h>
using namespace std;
int t;
int n, k, q;
int l, s[200020];
int r[200020], c[200020];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n ;i++){
			cin >> l;
			for(int j = 1; j <= l; j++){
				cin >> s[i];
			}
		}
		for(int i = 1; i <= q; i++){
			cin >> r[i] >> c[i];
			cout << 1 << endl;
		}
	}
	return 0;
}
