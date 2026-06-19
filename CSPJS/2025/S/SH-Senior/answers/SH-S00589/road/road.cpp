#include<iostream>
#include<cstdio>
#include<algorithm>
#include<random>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 10020, M = 1100010, K = 15;
mt19937 rnd(37);
int n, m, tm, k, f[N], c[K], id[N];
ll ans, sum;
int find(int x) {return x==f[x] ? x : f[x] = find(f[x]);}
struct edge {int x, y, w;} e[M];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> e[i].x >> e[i].y >> e[i].w;
	rep(i, 1, k){
		cin >> c[i];
		rep(j, 1, n){
			int x; cin >> x;
			e[m+(i-1)*n+j] = {j, i+n, x};
		}
	}
	sort(e+1, e+m+1, [&](const edge &x, const edge &y) {return x.w < y.w;});
	rep(i, 1, n) f[i] = i;
	rep(i, 1, m) if(find(e[i].x) != find(e[i].y)){
		f[find(e[i].x)] = find(e[i].y);
		e[++tm] = e[i]; ans += e[i].w;
	}
	rep(i, m+1, m+n*k) e[++tm] = e[i];
	m = tm;
	sort(e+1, e+m+1, [&](const edge &x, const edge &y) {return x.w < y.w;});
	rep(i, 0, (1<<k)-1) id[i] = i;
	shuffle(id, id+(1<<k), rnd);
	rep(l, 0, (1<<k)-1){
		int i = id[l];
		sum = 0; int cnt = n+__builtin_popcount(i)-1;
		rep(j, 1, n+k) f[j] = j;
		rep(j, 1, k) if(i>>(j-1)&1) sum += c[j];
		if(sum >= ans) continue;
		rep(j, 1, m) if(e[j].y <= n || (i>>(e[j].y-n-1)&1))
			if(find(e[j].x) != find(e[j].y)){
				f[f[e[j].x]] = f[e[j].y];
				cnt--; sum += e[j].w;
				if(!cnt || sum+(ll)cnt*e[j].w >= ans) break;
			}
		if(!cnt) ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
// g++ -std=c++14 -O2 -Wall -Wextra -Wno-unused-result -fsanitize=undefined road.cpp -o road
// cp road4.in road.in && time ./road && diff road.out road4.ans -b