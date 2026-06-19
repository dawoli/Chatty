#include<bits/stdc++.h>
using namespace std;

int n, q, ans;
string s1[200005], s2[200005];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i ++){
		string t1, t2;
		cin >> t1 >> t2;
		ans = 0;
		for (int j = 1; j <= n; j ++){
			for (int k = 1; k <= t1.size()-s1[j].size(); k ++){
				string t3 = t1;
				for (int l = k; l <= k+s1[j].size(); l ++){
					if (t3[l] == s1[j][l-k]) t3[l] = s2[j][l-k];
					else break;
				}
				if (t3 == t2) ans ++;
			}
		} 
		cout << ans;
	}
	return 0;
} 
