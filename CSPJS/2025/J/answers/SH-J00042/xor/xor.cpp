#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005];
// ^
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0, cnt = a[1];
	for(int i = 2; i <= n; i++){
		if(cnt == k){
			ans++;
			cnt = a[i];
		} 
		else cnt ^= a[i]; 
	}
	if(cnt == k) ans++;
	cout << ans;
	return 0;
}
