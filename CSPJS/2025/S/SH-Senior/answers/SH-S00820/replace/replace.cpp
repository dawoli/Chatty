#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = 200009;
string s1[N], s2[N];
int cha[N], sqianmian[N], shoumian[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= n; i++) {
		int s1size = s1[i].size();
		int s1index, s2index;
		for (int j = 0; j < s1size; j++) {
			if(s1[i][j] == 'b') {
				s1index = j;
				sqianmian[i] = j;
				shoumian[i] = s1size - j - 1;
				break;
			}
		}
		for (int j = 0; j < s1size; j++) {
			if(s2[i][j] == 'b') {
				s2index = j;
				break;
			}
		}
		int cha2 = s2index - s1index;
		cha[i] = cha2;
	}
		
	while(q--) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int t1Size = t1.size();
		int t2Size = t2.size();
		int t1qianmian, t1houmian;
		int t1index = 0, t2index = 0;
		if(t1Size != t2Size) {
			cout << "0" << endl;
			continue;
		}
		for (int i = 0; i < t1Size; i++) {
			if(t1[i] == 'b') {
				t1index = i;
				t1qianmian = i;
				t1houmian = t1Size - i - 1;
				break;
			}
		}
		for (int i = 0; i < t1Size; i++) {
			if(t2[i] == 'b') {
				t2index = i;
				break;
			}
		}
		int cha2 = t2index - t1index;
		for (int i = 1; i <= n; i++) {
			if (cha2 == cha[i] && t1qianmian >= sqianmian[i] && t1houmian >= shoumian[i]) ans++;
		}
		cout << ans;
		if(q) cout << endl;
	}
	return 0;
}
