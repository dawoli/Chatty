#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 1;
ll card[N], n, ans;
queue <ll> q;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1;i <= n;i++){
		scanf("%lld", &card[i]);
	}
	sort(card + 1, card + n + 1);
	for (ll i = 1;i <= n;i++){
		if (!q.empty() && q.front() < card[i]){
			q.pop();
		}
		q.push(card[i]);
	}
	ans = q.size();
	printf("%lld", ans);
	return 0;
}
