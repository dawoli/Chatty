#include <bits/stdc++.h>
using namespace std;
int t, n, r, c, l, q, k, cnt[10000];
vector <int> a[100005];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--){
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++){
			cin >> l;
			for (int j = 1; j <= n; j++){
				int m;
				cin >> m;
				a[i].push_back(m);
				cnt[m] = 1;
				
			}
		}while (q--){
			cin >> r >> c;
			if (!cnt[r] || !cnt[c]){
				cout << 0 << endl;
				continue;
			}
		}
	}return 0;
}
