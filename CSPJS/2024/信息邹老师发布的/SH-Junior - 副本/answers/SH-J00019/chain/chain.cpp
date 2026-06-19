#include<bits/stdc++.h>
using namespace std;

int T, n, k, q;

int main(){	
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i ++){
			int l;
			string s;
			cin >> l >> s;
		}
		for(int i = 1; i <= q; i ++){
			int r, c;
			cin >> r >> c;
			if(r % 2 == 0) cout << 0 << endl;
			else cout << 1 << endl;
		}
	}
	
	return 0;
}
