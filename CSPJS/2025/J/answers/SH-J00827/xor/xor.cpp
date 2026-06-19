#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+14;
int n, k, ans;
int a[N];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		int t;
		cin >> t;
		a[i] = a[i-1]^t;
	}
	for(int i = 1; i <= n; i ++){
		int j;
		for(j = i; j <= n; j ++){
			if((a[i-1]^a[j]) == k){
				i = j;
				ans ++;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
