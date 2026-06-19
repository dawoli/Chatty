#include <bits/stdc++.h>
using namespace std;
int T, n, k, q, l, r, c, judge = 0;
int ck[1005][1005];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i ++){
		cin >> n >> k >> q;
		for(int j = 1; j <= n; j ++){
			cin >> l;
			for(int m = 1; m <= l; m ++) cin >> ck[j][m];
		}
		for(int j = 1; j <= q; j ++){
			cin >> r >> c;
			for(int m = 1; m <= n; m ++){
				for(int o = 1; ; o ++){
					if(ck[m][o] == 0) break;
					if(ck[m][o] == c){
						judge = 1;
						break;
					}
				}
				if(judge == 1) break;
			}
			if(judge == 0) cout << 0 << endl;
			else cout << 1 << endl;
			judge = 0;
		}
	}
	return 0;
}
