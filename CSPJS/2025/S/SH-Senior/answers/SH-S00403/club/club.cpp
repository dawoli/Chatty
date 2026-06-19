#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 9;
#define re(i, n) for(ll i = 1; i <= n; i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
ll t, n, a[4][N];
struct Dat {
	ll val;
	ll d;
	bool operator < (const Dat &b) const {
		return val < b.val;
	}
} sum[N]; 
ll ans;
//priority_queue<tuple<ll, ll, ll>> heap;
//bool vis[N];
ll cnt[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		ans = 0;
		cin>>n;
		re(i, n) {
			re(j, 3) {
				cin>>a[j][i];
//				heap.emplace(a[j][i], i, j);
			}
		}
//		ll tmp = 0;
//		while(!heap.empty()) {
//			ll val, i, j;
//			tie(val, i, j) = heap.top();
//			heap.pop();
//			if(vis[i]) continue;
//			if(cnt[j] == n / 2) continue;
//			vis[i] = 1;
//			cnt[j]++;
//			tmp += val;	
//		}
//		ans = tmp;
		re(j, 3) {
			re(i, 3) cnt[i] = 0; 
			ll res = 0;
			ll o, p;
			if(j == 1) o = 2, p = 3;
			else if(j == 2) o = 1, p = 3;
			else o = 1, p = 2;
			re(i, n) {
				sum[i].val = a[j][i] - max(a[o][i], a[p][i]);
				res += max(a[o][i], a[p][i]);
				if(a[o][i] > a[p][i]) cnt[o]++, sum[i].d = o;
				else cnt[p]++, sum[i].d = p;
			}
			sort(sum + 1, sum + n + 1);
			for(int i = n; i >= n / 2 + 1; i--) {
				if(sum[i].val < 0 && cnt[o] <= n / 2 && cnt[p] <= n / 2) break;
				res += sum[i].val;
				cnt[sum[i].d]--;
			}
			ans = max(ans, res);
		} cout<<ans<<endl;
	}
	return 0;
}

