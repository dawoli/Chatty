#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 5e5 + 10;
ll n, k, a[maxn], ls = 0, sum, cnt = 0;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
		sum = 0;
		for (ll j = i; j >= ls + 1; j--){
			sum ^= a[j];
			if (sum == k){
				cnt++;
				ls = i;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
