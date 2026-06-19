#include <bits/stdc++.h>
using namespace std;

int n, x, flag = 1, ans;
int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] != 1 && a[i] != 0) flag = 0;
	}
	if(flag == 1) {
		if(x != 1 && x != 0) {
			cout << 0;
			return 0;
		}
		if(x == 0) {
			int cnt = 1;
			while(cnt <= n) {
				if(a[cnt] == 0) {
					cnt++;
					ans++; 
				}
				else if(a[cnt] == 1 && a[cnt + 1] == 1) {
					cnt += 2;
					ans++;
				}
				else cnt++;
			}
		}
		if(x == 1) {
			for(int i = 1; i <= n; i++) {
				if(a[i] == 1) ans++;
			}
		}
	}
	else {
		int tmp = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if((i == 1 && j == 1) || tmp == 0) tmp == i ^ j;
				else if(tmp ^ i ^ j == x) {
					tmp = 0;
					ans++;
				}
				else tmp = tmp ^ i ^ j;
			}
		}
	}
	cout << ans;
	return 0;
} 
