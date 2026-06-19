#include <bits/stdc++.h>
using namespace std;
int cnt[1000];
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		int a[n];
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]]++;
			if(cnt[a[i]] >= 2){
				ans += a[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
