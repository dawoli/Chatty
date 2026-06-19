#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100010;
const ll MAXL = 1000010;
ll T;
ll n, m, L, V;
ll p[N];
struct info{
	ll l, r;
} car[N];
ll cnt, Timer, Now;
ll pt, Left[MAXL], Right[MAXL];
bool cmp(const info &x, const info &y) {
	return x.r < y.r || (x.r == y.r && x.l < y.l);
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
		for(ll i = 1; i <= n; i++) {
			ll d, v, a;
			scanf("%lld %lld %lld", &d, &v, &a);
			if(a == 0) {
				if(v > V) car[i] = (info) {d, L};
				else car[i] = (info) {L + 1, L};
			} else if(a > 0) {
				if(v > V) car[i] = (info) {d, L};
				else car[i] = (info) {d + (V * V - v * v) / (2 * a) + 1, L};
			}
			else if(a < 0) {
				if(v <= V) car[i] = (info) {L + 1, L};
				else car[i] = (info) {d, d + (v * v - V * V - 1) / (2 * -a)};
			}
			car[i].r = min(L, car[i].r);
		}
		for(ll i = 1; i <= m; i++) scanf("%lld", &p[i]);
		pt = 0;
		for(ll x = 0; x <= L; x++) {
			if(pt <= m - 1 && x >= p[pt + 1]) pt++;
			Left[x] = pt;
		}
		pt = m + 1;
		for(ll x = L; x >= 0; x--) {
			if(pt >= 2 && x <= p[pt - 1]) pt--;
			Right[x] = pt;
		}
		cnt = 0;
		for(ll i = 1; i <= n; i++) {
			if(car[i].l > L) continue;
			if(Right[car[i].l] > m) continue;
			if(Right[car[i].l] <= Left[car[i].r]) car[++cnt].l = Right[car[i].l], car[cnt].r = Left[car[i].r];
		}
		sort(car + 1, car + 1 + cnt, cmp);
		Timer = 0, Now = 0;
		for(ll i = 1; i <= cnt; i++) {
			if(car[i].l <= Now) continue;
			Timer++, Now = car[i].r;
		}
		printf("%lld %lld\n", cnt, m - Timer);
	}
	return 0;
}
