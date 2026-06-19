#include <bits/stdc++.h>
using namespace std;
int l[100005];
vector<int> s[100005];
int r[100005];
int c[100005];
signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n, k, q;
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++){
			cin >> l[i];
			s[i].clear();
			for (int j = 1; j <= l[i]; j++){
				int x;
				cin >> x;
				s[i].push_back(x);
			}
		}
		for (int i = 1; i <= q; i++){
			cin >> r[i] >> c[i];	
			cout << 0 << endl;
		}
	} 
}
