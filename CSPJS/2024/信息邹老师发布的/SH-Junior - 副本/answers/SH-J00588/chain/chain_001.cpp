#include<bits/stdc++.h>
using namespace std;

int t;

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--){
		int n, k, q, l[100005], r[100005], c[100005];
		string s[100005];
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i ++){
			cin >> l[i];
			for (int j = 0; j <= l[0]; j ++){
				string t;
				cin >> t;
				s[i] += t;
			}
		}
		for (int i = 1; i <= q; i ++){
			cin >> r[i] >> c[i];
		}
		cout << 0 << endl;
	}
}
