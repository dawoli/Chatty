#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int ans = 0;
	bool flag = 0;
	int now = a[0];
	if(now == k) {
		ans++;
		flag = 1;
	}
	for(int i = 1;i < n;i++) {
		if(flag) {
			now = a[i];
			flag = 0;
		}
		else {
			now = now ^ a[i];
		}
		if(now == k) {
			ans++;
			flag = 1;
		}
	}
	cout << ans;
	return 0;
}
