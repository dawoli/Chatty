#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll n, m, k, tot = 0;
ll ans = 1e18, as;
pair<ll, pair<ll, ll> > edg[2000005];
ll tc[100005];
ll fa[100005];
ll c[100005];
ll flag[100005];
vector <pair<ll, ll> > to[100005];
// map<ll, ll> mp[100005], mp2[100005];
// ll bcj(ll x){
// 	return fa[x]==x?x:fa[x]=bcj(fa[x]);
// }
// void merge(ll u, ll v){
// 	u = bcj(u);
// 	v = bcj(v);
// 	if(u==v)
// 		return;
// 	fa[u] = v;
// }
priority_queue <pair<pair<ll, ll>, pair<ll, ll> > > pq;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for(ll i = 1;i <= m;i++){
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		edg[i].first = w;
		edg[i].second = make_pair(u, v);
		// mp[u][v] = w;
		// mp[v][u] = w;
	}
	tot = m;
	bool flagA = 1;
	for(ll i = 1;i <= k;i++){
		scanf("%lld", &c[i]);
		flagA &= (c[i] == 0);
		for(ll j = 1;j <= n;j++){
			scanf("%lld", &tc[j]);
		}
		// edg[++tot] = make_pair(c[i], make_pair(n+i, i));
		for(ll j = 1;j <= n;j++){
			if(j==i)
				continue;
			edg[++tot] = make_pair(tc[j], make_pair(n+i, j));
			// mp2[i][j] = tc[j];
			// mp2[j][i] = tc[j];
		}
	}
	// for(ll i = 1;i <= n+k;i++){
	// 	fa[i] = i;
	// }
	sort(edg+1, edg+1+tot);
	for(ll i = 1;i <= tot;i++){
		to[edg[i].second.first].push_back(make_pair(-edg[i].first, edg[i].second.second));
		to[edg[i].second.second].push_back(make_pair(-edg[i].first, edg[i].second.first));
	}
	for(ll i = flagA?((1<<k)-1):0;i < (1<<k);i++){
	// for(ll i = 1023;i <= 1023;i++){
		while(!pq.empty())pq.pop();
		as = 0;
		for(ll i = 1;i <= n+k;i++){
			flag[i] = 0;
		}
		int ct = 0;
		for(ll j = 1;j <= k;j++){
			if((i>>(j-1))&1){
				ct++;
				// merge(j, n+j);
				as += c[j];
			}else{
				flag[n+j] = 1;
			}
		}
		flag[1] = 1;
		pq.push(make_pair(to[1][0], make_pair(1, 1)));
		// cout << "!" << 1 << endl;
		if(1 <= k){
			if(i&1){
				pq.push(make_pair(to[1+n][0], make_pair(1+n, 1)));
				flag[1+n] = 1;
			}
		}
		ll cnt = 0;
		while(!pq.empty() && cnt < n-1){
			pair<pair<ll, ll>, pair<ll, ll> > f = pq.top();
			pq.pop();
			ll u = f.second.first, v = f.first.second, w = -f.first.first;
			if(flag[v]){
				if(to[u].size() > f.second.second){
					pq.push(make_pair(to[u][f.second.second], make_pair(u, f.second.second+1)));
				}
				continue;
			}
			flag[v] = 1;
			as += w;
			cnt++;
			if(to[u].size() > f.second.second){
				pq.push(make_pair(to[u][f.second.second], make_pair(u, f.second.second+1)));
			}
			pq.push(make_pair(to[v][0], make_pair(v, 1)));
			if(v <= k){
				if((i>>(v-1))&1){
					pq.push(make_pair(to[v+n][0], make_pair(v+n, 1)));
					// if(flag[v+n]){
					// 	// cout << "!!!!" << endl;
					// 	exit(0);
					// }
					flag[v+n] = 1;
				}
			}
			if(v > n){
				pq.push(make_pair(to[v-n][0], make_pair(v-n, 1)));
				// if(flag[v-n]){
				// 	cout << "!!!!!" << endl;
				// 	exit(0);
				// }
				flag[v-n] = 1;
			}
		}
		// cout << cnt << endl;
		// cout << as << "--------------------" << endl;
		// for(int i = 1;i <= n;i++){
		// 	if(!flag[i]){
		// 		cout << "!!!!" << endl;
		// 	}
		// 	if(bcj(i) != bcj(1)){
		// 		cout << "!!!!" << endl;
		// 	}
		// }
		ans = min(ans, as);
	}
	printf("%lld\n", ans);
	return 0;
}