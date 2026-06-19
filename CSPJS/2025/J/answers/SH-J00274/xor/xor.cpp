#include<bits/stdc++.h>
using namespace std;
//#define int long long

int xr[500005], a[500005];
int n, k;

int dfs(int l, int r, int end){
	if(l <= end){
		return dfs(end + 1, r + 1, end);
	}
	if(r > n){
		return 0;
	}
	if((xr[r] ^ xr[l - 1]) == k){
		return 1 + dfs(r + 1, r + 1, r);
	}else{
		return max(dfs(l - 1, r, end), dfs(end + 1, r + 1, end));
	}
}

map<int, int> mp;

signed main(){
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	long long ans = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		xr[i] = xr[i - 1] ^ a[i];
	}
	if(k == 0){
		int last = 0;
		for(int i = 1;i <= n;i++){
			if(mp[xr[i]] > last){
				mp[xr[i]] = 0;
				last = i;
				ans++;
			}else{
				mp[xr[i]] = i;
			}
		}
		cout << ans;
		return 0;
	}
	int l = 1, r = 1;
//	while(r <= n){
//		if(l > r){
//			r = l + 1;
//			continue;
//		}else if((xr[r] ^ xr[l - 1]) == k){
//			ans++;
//			l = r + 1
//		}else{
//			l++;
//		}
//	}
	cout << dfs(1, 1, 0);
	return 0;
}
