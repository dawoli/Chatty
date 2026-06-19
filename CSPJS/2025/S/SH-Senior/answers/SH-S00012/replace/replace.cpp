#include <bits/stdc++.h>
using namespace std;
string s[200010][2];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	while (q--){
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()){
			cout << 0 << endl;
			continue;
		}
		int l1 = t1.size();
		int cnt = 0;
		for (int i = 0; i < l1; i++){
			for (int j = i; j < l1; j++){
				for (int k = 1; k <= n; k++){
					if (s[k][0].size() != j - i + 1) continue;
					bool flag = true;
					for (int t = i; t <= j; t++){
						if (t1[t] != s[k][0][t-i]){
							flag = false;
//							if (i == 2 && j == 3){
//								 cout << t1[t] << " " << s[k][0][t-i] << endl;
//							}
						}
					}
					if (flag){
						bool flag_ = true;
						for (int t = 0; t < l1; t++){
							if (t >= i && t <= j){
								if (t2[t] != s[k][1][t-i]){
									flag_ = false;
								}
							} else {
								if (t2[t] != t1[t]){
									flag_ = false;
								}
							}
						}
						if (flag_){
							cnt++;
							// cout << s[k][0] << " " << s[k][1] << endl;
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
