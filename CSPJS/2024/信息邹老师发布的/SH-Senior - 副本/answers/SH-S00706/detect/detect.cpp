#include <bits/stdc++.h>
using namespace std;
int t, n, m, l, p[100005], val[100005], f[100005];
double v;

struct Car{
	double v, a, lb, ub;
	int d, lp, up;
	bool c;
	bool operator< (Car o) const{
		return lb < o.lb;
	}
} car[100005];

int cone(int u){
	int ans = 0;
	while(u){
		++ ans;
		u &= u - 1;
	}
	return ans;
}

void solve1(){
	bool f, o;
	int ans = 0;
	for(int x = 0; x < (1 << m); x ++){
		f = 1;
//		cout << bitset<5>(x) << ' ';
		for(int i = 1; i <= n; i ++) if(!car[i].c){
			o = 1;
			for(int j = car[i].lp; j <= car[i].up; j ++) if((x >> (j - 1)) & 1){
				o = 0;
				break;
			}
			if(o){
				f = 0;
				break;
			}
//			cout << i << endl;
		}
		if(f) ans = max(ans, m - cone(x));
	}
	cout << ans << endl;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n >> m >> l >> v;
		int novr = n;
		for(int i = 1; i <= n; i ++){
			cin >> car[i].d >> car[i].v >> car[i].a;
			if(car[i].a > 0){
				double s = (v * v - car[i].v * car[i].v) / car[i].a / 2.00;
				car[i].lb = s + car[i].d;
				car[i].ub = l + 1;
			}
			else if(car[i].a < 0){
				if(car[i].v < v){
					car[i].lb = l + 1;
					car[i].ub = l + 1;
				}
				else{
					double s = (v * v - car[i].v * car[i].v) / car[i].a / 2.00;
					car[i].ub = s + car[i].d;
					car[i].lb = car[i].d;
				}
			}
			else if(car[i].v > v){
				car[i].lb = car[i].d;
				car[i].ub = l + 1;
			}
			else{
				car[i].lb = l + 1;
				car[i].ub = l + 1;
			}
			car[i].c = 0;
		}
		for(int i = 1; i <= m; i ++) cin >> p[i];
		sort(car + 1, car + n + 1);
		sort(p + 1, p + m + 1);
		car[1].lp = 1;
		car[1].up = m;
		while(p[car[1].lp - 1] >= car[1].lb && car[1].lp > 0) -- car[1].lp;
		while(p[car[1].lp] < car[1].lb && car[1].lp <= m) ++ car[1].lp;
		while(p[car[1].up] >= car[1].ub && car[1].up > 0) -- car[1].up;
		while(p[car[1].up + 1] < car[1].ub && car[1].up < m) ++ car[1].up;
		++ val[car[1].lp];
		-- val[car[1].up];
		if(car[1].lp > m || car[1].lp > car[1].up){
			-- novr;
			car[1].c = 1;
//			cout << '-';
		}
//		printf("%llf %llf %d %d\n", car[1].lb, car[1].ub, car[1].lp, car[1].up);
//		memset(val, 0, sizeof(val));
		for(int i = 2; i <= n; i ++){
			car[i].lp = car[i - 1].lp;
			car[i].up = car[i - 1].up;
			while(p[car[i].lp - 1] >= car[i].lb && car[i].lp > 0) -- car[i].lp;
			while(p[car[i].lp] < car[i].lb && car[i].lp <= m) ++ car[i].lp;
			while(p[car[i].up] >= car[i].ub && car[i].up > 0) -- car[i].up;
			while(p[car[i].up + 1] < car[i].ub && car[i].up < m) ++ car[i].up;
			++ val[car[i].lp];
			-- val[car[i].up + 1];
			if(car[i].lp > m || car[i].lp > car[i].up){
				-- novr;
				car[i].c = 1;
			}
//			if(car[i].lp > m || car[i].lp > car[i].up) cout << '-';
//			printf("%llf %llf %d %d\n", car[i].lb, car[i].ub, car[i].lp, car[i].up);
		}
		cout << novr << ' ';
//		for(int i = 1; i <= m; i ++) val[i] += val[i - 1]; 
//		for(int i = 1; i <= m; i ++) for(int j = m; j; j --) f[j] = max(f[j], f[j - 1] + val[i]);
//		for(int i = 1; i <= m; i ++) if(f[i] >= n){
//			cout << m - i << endl;
//			break;
//		}
		solve1();
	}
	return 0;
}
