#include<bits/stdc++.h>
using namespace std;
int cnt[15], p = 0, ans[1000005];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int f = s.size();
	for(int i = 0; i < f; i++) {
		if(isdigit(s[i])) {
			cnt[s[i] - '0']++;
			p++;
		}
	}
	int j = 0;
	for(int i = 9; i >= 0; i--) {
		while(cnt[i] > 0) {
			ans[j] = i;
			cnt[i]--;
			j++;
		}
	}
	for(int i = 0; i < p; i++) {
		cout << ans[i];
	}
	return 0;
}
