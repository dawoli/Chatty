#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n,m,ans,c[N];
string s; 
bool vis[N]; 
void input() {
	cin>>n>>m;
	cin>>s; s = '.' + s;
	for(ll i = 1;i <= n;i++) cin>>c[i];
}
void dfs(ll pos,ll cnt,ll cnt2) {
	if(pos == n + 1) {
		if(cnt2 >= m) ans += 1;
		return;
	}
//	cout<<pos<<" "<<cnt<<" "<<cnt2<<'\n';
	for(ll i = 1;i <= n;i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		bool flag = 0;
		if(c[i] > cnt && s[pos] == '1') {
			flag = 1; cnt2 += 1;
		}
		else cnt += 1;
		dfs(pos + 1,cnt,cnt2);
		vis[i] = 0;
		if(flag) cnt2 -= 1;
		else cnt -= 1;
	}
}
void solve1() {
	ans = 0; dfs(1,0,0); cout<<ans<<'\n';
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	if(n <= 18) {
		solve1();
	}
	return 0;
} 
