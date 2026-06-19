#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, k, a[500005];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int cnt = 1;
	int ans = 0;
	while(cnt <= n){
		int ans2 = a[cnt];
		cnt++;
		while(ans2 != k){
			ans2 = ans2 ^ a[cnt];
			cnt++;
			if(cnt == n){
				cout << 69;
				return 0;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}
