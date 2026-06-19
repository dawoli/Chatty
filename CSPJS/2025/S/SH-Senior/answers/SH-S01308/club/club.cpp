#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 1;
ll t, n, ans, a_cnt, b_cnt, c_cnt, present, base;
struct node{
	ll a, b, c;
}member[N];
void init(){
	present = base = a_cnt = b_cnt = c_cnt = ans = n = 0;
	memset(member, 0, sizeof(member));
}
void dfs(ll x){
	if (x == n + 1){
		ans = max(ans, base + present);
		return;
	}
	if (a_cnt < n / 2){
		a_cnt++;
		present += member[x].a;
		dfs(x + 1);
		present -= member[x].a;
		a_cnt--;
	}
	if (b_cnt < n / 2){
		b_cnt++;
		present += member[x].b;
		dfs(x + 1);
		present -= member[x].b;
		b_cnt--;
	}
	if (c_cnt < n / 2){
		c_cnt++;
		present += member[x].c;
		dfs(x + 1);
		present -= member[x].c;
		c_cnt--;
	}
}
bool cmp(node aa, node bb){
	return aa.a >= bb.a;
}
bool judge_a(){
	for (ll i = 1;i <= n;i++){
		if (member[i].b || member[i].c){
			return 0;
		}
	}
	return 1;
}
bool judge_b(){
	for (ll i = 1;i <= n;i++){
		if (member[i].c){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (ll i = 1;i <= t;i++){
		init();
		cin >> n;
		for (ll j = 1;j <= n;j++){
			cin >> member[j].a >> member[j].b >> member[j].c;
			ll q = min(member[j].a, min(member[j].b, member[j].c));
			base += q;
			member[j].a -= q;
			member[j].b -= q;
			member[j].c -= q;
		}
		if (judge_a()){
			sort(member + 1, member + n + 1, cmp);
			for (ll j = 1;j <= n;j++){
				present += member[j].a;
			}
			ans = base + present;
		}else if (!judge_b()){
			dfs(1);
		}else{
			for (ll j = 1;j <= n;j++){
				base += member[j].b;
				member[j].a -= member[j].b;
			}
			sort(member + 1, member + n + 1, cmp);
			for (ll j = 1;j <= n / 2;j++){
				present += member[j].a;
			}
			ans = base + present;
		}
		cout << ans << "\n";
	}
	return 0;
}
