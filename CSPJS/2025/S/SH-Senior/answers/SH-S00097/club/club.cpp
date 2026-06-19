#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long mp[MAXN][4];
long long ans = 0;
long long n;
void dfs(long long num, long long a, long long b, long long c, long long tempans){
	if(num == n + 1){
		ans = max(ans, tempans);
		return;
	}
	if(a < n / 2){
		dfs(num + 1, a + 1, b, c, tempans + mp[num][1]);
	}
	if(b < n / 2){
		dfs(num + 1, a, b + 1, c, tempans + mp[num][2]);
	}
	if(c < n / 2){
		dfs(num + 1, a, b, c + 1, tempans + mp[num][3]);
	}
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(long long i = 1; i <= n; i++){
			for(long long j = 1; j <= 3; j++){
				cin >> mp[i][j];
			}
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
} 
