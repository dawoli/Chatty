#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100005], cnt[100005];
signed main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	int sum = 0, ans = n;
	for (int i = 1; i <= 100000; i++){
		if (cnt[i] != 0){
			if (cnt[i] < sum){
				ans -= cnt[i];
			}
			else{
				ans -= sum;
				sum = cnt[i];
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
