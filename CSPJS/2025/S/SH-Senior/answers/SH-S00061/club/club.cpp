#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N][5];
ll ans = 0;
void dfs(int pos, int cnt1, int cnt2, int cnt3, ll sum) {
	if(pos == n+1) {
		ans = max(ans, sum);
		return ;
	}
	if(cnt1+1 <= n/2) dfs(pos+1, cnt1+1, cnt2, cnt3, sum+a[pos][1]);
	if(cnt2+1 <= n/2) dfs(pos+1, cnt1, cnt2+1, cnt3, sum+a[pos][2]);
	if(cnt3+1 <= n/2) dfs(pos+1, cnt1, cnt2, cnt3+1, sum+a[pos][3]);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
			}
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
