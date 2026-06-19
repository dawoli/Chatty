#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
int n;
int a[N], cnt[N];
LL s[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i], cnt[a[i]] ++;
//	for(int i = 1; i < N; i ++) s[i] = s[i - 1] + cnt[i];
	
	int c = 0, res = n;
	for(int i = 1; i < N; i ++){
		if(c >= cnt[i]){
			c -= cnt[i]; res -= cnt[i];
		}
		else{
			res -= c, c = 0;
		}
		c += cnt[i];
//		if(i == 2) cout << c << ' ' << res << '\n';
	}
	cout << res;
	
//	sort(a + 1, a + 1 + n);
//	int cnt = 0, last = -1, res = n;
//	
//	for(int i = 1; i <= n; i ++){
//		if(last == -1 || cnt){
//			cnt --; res --;
//		}
//		else {
//			cnt ++;
//		}
//	}
}

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	solve();
	
	return 0;
}
