#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int pe[n+1];
		int cnt[200005] = {0};
		int maxn = 0;
		int v= 0;
		for(int i = 1; i <= n; i++) {
			cin >> pe[i];
			if(pe[i] > maxn)
				maxn = pe[i];
			cnt[pe[i]]++;
		}
		for(int i = 1; i <= maxn; i++) {
			if(cnt[i] != 0) {
				v += (cnt[i] - 1) * i;
			}
		}
		cout << v << endl;
	}
	
	return 0;
}
