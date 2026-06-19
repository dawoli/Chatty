#include <bits/stdc++.h>
using namespace std;
const int L = 2e5+10;
int s[L];
bool check(int r, int c){
	
}
int main(){
	ios::sync_with_stdio(false);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		memset(s, 0, sizeof(s));
		int n, k, q;
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++){
			int l;
			cin >> l;
			for (int j = 1; j <= l; j++) cin >> s[j];
		}
		for (int i = 1; i <= q; i++){
			int r, c;
			cin >> r >> c;
			if (check(r, c)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
