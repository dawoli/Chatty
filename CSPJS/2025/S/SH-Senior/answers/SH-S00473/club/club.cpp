#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll t, n;
ll a[100005][4];
vector <ll> b[4];
ll ans = 0;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		ans = 0;
		b[0].clear();
		b[1].clear();
		b[2].clear();
		scanf("%lld", &n);
		for(ll i = 1;i <= n;i++){
			scanf("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);
			ll mx = max(a[i][0], max(a[i][1], a[i][2]));
			ll tmp = a[i][0]+a[i][1]+a[i][2]-mx-min(min(a[i][0], a[i][1]), a[i][2]);
			ans += mx;
			if(mx == a[i][0]){
				b[0].push_back(mx-tmp);
			}else if(mx == a[i][1]){
				b[1].push_back(mx-tmp);
			}else if(mx == a[i][2]){
				b[2].push_back(mx-tmp);
			}
		}
		ll mb = 0;
		if(b[1].size() > b[0].size()){
			mb = 1;
		}
		if(b[2].size() > b[mb].size()){
			mb = 2;
		}
		sort(b[mb].begin(), b[mb].end());
		for(ll i = 0;i+n/2 < b[mb].size();i++){
			ans-=b[mb][i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}