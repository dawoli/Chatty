#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int ans = 0, cnt = 1;
	for(int i = 2; i <= n; i++) {
		int x = a[i];
		if(x == a[i-1]){
			cnt++;
		}
		else {
			if(ans < cnt) ans = cnt;
			cnt = 1;
		}
	}
	cout<< ans;
	return 0;
}
