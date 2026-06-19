#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
#define R 105
#define M 2005
ll T, n, k, q, r, t;
ll l[N], S[N][M];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> k >> q;
		for(ll i = 1; i <= n; i++){
			cin >> l[i];
			for(ll j = 1; j <= l[i]; j++) cin >> S[i][j];
		}
		for(ll g = 1; g <= q; g++){
			cin >> r >> t;
			bool falg = false;
			for(ll i = 1; i <= n; i++){
				ll l1 = -INT_MAX;
				for(ll j = 1; j <= l[i]; j++){
					if(S[i][j] == 1) l1 = j;
					if(S[i][j] == t && j - l1 < k) falg = true;
				}
			}
			if(falg) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
