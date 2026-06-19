#include <bits/stdc++.h> 


using namespace std;
using ll = long long;
int n;
ll a[300010], b[300010], c[300010], cost1[300010], cost2[300010];
int cnt1, cnt2, cnt3;

void solve() {
	cnt1 = 0;
	cnt2 = 0;
	cnt3 = 0;
	scanf("%d", &n);
	ll ans = 0;
	priority_queue<ll, vector<ll>, greater<ll> > pq1, pq2, pq3;
	for (int i=1;i<=n;i++) {
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		ll mx = max(max(a[i], b[i]), c[i]);
		if (a[i] == mx) {
			ans += a[i];
			cnt1++;
			cost1[i] = a[i]-b[i];
			cost2[i] = a[i]-c[i];
			if (cost1[i] > cost2[i]) swap(cost1[i], cost2[i]);
			
		} else if (b[i]==mx){ 
			ans += b[i];
			cnt2++;
			cost1[i] = b[i]-a[i];
			cost2[i] = b[i]-c[i];
			if (cost1[i] > cost2[i]) swap(cost1[i], cost2[i]);
		} else {
			// c[i]==mx
			ans += c[i];
			cnt3++;
			cost1[i] = c[i]-a[i];
			cost2[i] = c[i]-b[i];
			if (cost1[i] > cost2[i]) swap(cost1[i], cost2[i]);
		}
		if (a[i]==mx) pq1.push(cost1[i]); 
		else if (b[i]==mx) pq2.push(cost1[i]); 
		else if (c[i]==mx) pq3.push(cost1[i]); 
		// cerr<<mx<<" "<<cost1[i]<<endl;
	}
	if (cnt1 > n/2) while (cnt1 > n/2) {ans -= pq1.top();pq1.pop();cnt1--;}
	else if (cnt2 > n/2) while (cnt2 > n/2) {/*cerr<<pq2.top()<<"->"<<ans-pq2.top()<<endl;*/ans -= pq2.top();pq2.pop();cnt2--;}
	else if (cnt3 > n/2) while (cnt3 > n/2) {/*cerr<<pq3.top()<<"->"<<ans-pq3.top()<<endl;*/ans -= pq3.top();pq3.pop();cnt3--;}
	
	printf("%lld\n", ans);
	
	
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T = 1;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
