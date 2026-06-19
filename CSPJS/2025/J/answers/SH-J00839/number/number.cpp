#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int now = 0;
	bool flag = 1;
	for(int i = 0;i < s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[now] = s[i] - '0';
			if(a[now] != 0) {
				flag = 0;
			}
			now++;
		}
	}
	if(flag) {
		cout << 0;
		return 0;
	}
	sort(a,a + now);
	for(int i = now - 1;i >= 0;i--) {
		cout << a[i];
	}
	return 0;
}
