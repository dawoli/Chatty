#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q, tot = 0;
string sa[200005], sb[200005];
string ta, tb;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> sa[i] >> sb[i];
	}
	while (q--){
		cin >> ta >> tb;
		int l, r;
		for (int i = 0; i < ta.size(); i++){
			if (ta[i] != tb[i]){
				l = i;
				break;
			}
		}
		for (int i = ta.size() - 1; i >= 0; i--){
			if (ta[i] != tb[i]){
				r = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 0; i <= l; i++){
			for (int u = 1; u <= n; u++){
				if (i + sa[u].size() - 1 < r){
					continue;
				}
				int flag = 1;
				for (int j = 0; j < sa[u].size(); j++){
					if (ta[i + j] != sa[u][j] || tb[i + j] != sb[u][j]){
						flag = 0;
						break;
					}
				}
				ans += flag;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

