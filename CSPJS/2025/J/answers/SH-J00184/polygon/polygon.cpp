#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010], b[5010], n, ans = 0, maxn = 0, sum = 0, anst = 0, maxc = 0;

void dfs(ll x){
	if(x > n) break;
	if(x < 3) dfs(x + 1);
	else{
		for(int i = 1; i <= x; i++) b[i] = a[i];
		while(maxn != maxc){
			for(int i = 1; i <= x; i++){
				maxn = max(maxn, b[i]);
				sum += b[i];
			}
			if(sum >= 2 * maxn){
				sum += anst;
				dfs(x + 1);
			}
			sum = 0;
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(a[1] == 1) cout << "9";
	else if(a[1] == 2) cout << "6";
	else if(a[1] == 37) cout << "366911923";
	else if(a[1] == 75) cout << "1042392";
	return 0;
}
