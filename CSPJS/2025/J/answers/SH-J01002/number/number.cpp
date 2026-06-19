#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int cnt[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); i ++) {
		if ('0'<=s[i]&&s[i]<='9') {
			cnt[s[i]-'0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		while (cnt[i]--) {
			cout<<i;
		}
	}
	return 0;
}
