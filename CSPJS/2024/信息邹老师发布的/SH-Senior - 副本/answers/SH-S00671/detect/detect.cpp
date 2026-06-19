#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e5 + 5;
struct node{
	ll d, v, a;
};
node car[maxn];
bool cmp(node x, node y){
	return x.v > y.v;
}
ll pos[maxn];
ll n, m, L, V, T;
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	bool flag = true;
	while(T--){
		scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
		flag = true;
		for(ll i = 1; i <= n; i++){
			scanf("%lld %lld %lld", &car[i].d, &car[i].v, &car[i].a);
			if(car[i].a == 0)
				flag = false;
		}
		sort(car + 1, car + n + 1, cmp);
		ll ans = 0;
		for(ll i = 1; i <= m; i++)
			scanf("%lld", pos + i);
		if(flag){
			double speed;
			for(ll i = 1; i <= n; i++){
				speed = sqrt((double)(car[i].v * car[i].v + 2 * car[i].a * (pos[m] - car[i].d)));
				if(speed > (double)(V) && car[i].d <= pos[m])
					ans++;
			}
		}
		else{
			for(ll i = 1; i <= n; i++){
				if(car[i].v <= V)
					break;
				if(car[i].d <= pos[m])
					ans++;
			}
		}
		if(ans == 0)
			printf("%lld %lld\n", ans, m);
		else
			printf("%lld %lld\n", ans, m - 1);
	}
	return 0;
}
