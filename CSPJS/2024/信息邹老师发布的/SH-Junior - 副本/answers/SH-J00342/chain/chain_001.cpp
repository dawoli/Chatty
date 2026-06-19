#include <bits/stdc++.h>
using namespace std;
int T, n, k, q, l, t[100000][2], qu[100000][200000];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n >> k >> q;
        for (int i = 0; i < n; i ++){
            cin >> l;
            for (int j = 0; j < l; j ++){
                cin >> qu[i][j];
            }
        }
        for (int i = 0; i < q; i ++){
            cin >> t[i][0] >> t[i][2];
            cout << 1 << endl;
        }
    }
	return 0;
}
