#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[500005];
int main(){
	//freopen("xor","in",stdin);
	//freopen("xor","out",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ll ans1 = 0;
		for(int j = i;j <= n;j++){
			ll sum = a[i];
			for(int k = i + 1;k <= j;k++){
				sum ^= a[k];
			}
			if(sum == k) ans1++;
		}
		ans += ans1;
	}
	cout << ans;
	
	return 0;
}
