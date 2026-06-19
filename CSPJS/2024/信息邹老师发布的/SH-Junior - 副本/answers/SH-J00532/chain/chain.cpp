#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t; cin >> t;
	while(t--){
		int n, k, q;
		cin >> n >> k >> q;
		vector<int> l(n + 1), s[n + 1];
		for (int i = 1; i <= n; i++){
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++){
				int x; cin >> x;
				s[i].push_back(x);
			}
		} while(q--){
			int r, c; cin >> r >> c;
			bool yes1 = 0, yes2 = 0, yes = 0;
			pair<int, int> pos1[100005], pos2[100005]; 
			int num1 = 0, num2 = 0;
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= l[i]; j++){
					if (s[i][j] == 1){
						yes1 = 1;
						pos1[++num1] = {i, j};
					} if (s[i][j] == c){
						yes2 = 1;
						pos2[++num2] = {i, j};
					}
				}
			} if (!yes1 || !yes2){
				cout << 0 << endl;
				continue;
			} if (r == 1){
				for (int i = 1; i <= num1; i++){
					for (int j = pos1[i].second + 1; j <= pos[i].second + k; j++){
						if (s[pos[i].first][j] == c){
							cout << 1 << endl;
							yes = 1;
							break;
						}
					} if (yes) break;
				} if (!yes) cout << 0;
				continue;
			} cout << 0 << endl;
		}
	} return 0;
}
