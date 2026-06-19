#include <bits/stdc++.h>
using namespace std;

long long t;
long long n, m, l, max_v; // n车数 m测速仪数 l公路长度 v限速 
bool p[1000001], p_Bpass_byOScar[1000001];
struct Car {
	long long d, v, a; // d距离 v速度 a加速度 
} car[100001];

int main () {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	for (long long o = 1; o <= t; o++) {
		cin >> n >> m >> l >> max_v;
		for (long long i = 1; i <= n; i++) {
			cin >> car[i].d >> car[i].v >> car[i].a;
		}
		long long disS_tmBig_p = 0;
		long long lsbl;
		for (long long i = 1; i <= m; i++) {
			cin >> lsbl;
			if (lsbl > disS_tmBig_p) disS_tmBig_p = lsbl;
			p[lsbl] = 1;
		}
		long long cnt_OScar = 0;
		//ll max_speed = 0;
		for (long long i = 1; i <= n; i++) {
			if (car[i].v > max_v) cnt_OScar++;
			//if (car[i].v > max_speed) max_speed = car[i].v;
		}
		cout << cnt_OScar << ' ';
		/*
		ll cnt_canBxp = m;
		for (ll i = 1; i <= n; i++) {
			if (p_Bpass_byOScar[i] == 1) {
				cnt_canBxp--;
			} 
		}
		cout << cnt_canBxp << endl;
		*/
		long long disS_tmSmall_beg = l;
		for (long long i = 1; i <= n; i++) {
			if(car[i].d < disS_tmSmall_beg) disS_tmSmall_beg = car[i].d;
		}
		long long cnt_CBxp = 0;
		for (long long i = 1; i <= disS_tmBig_p; i++) {
			if (p[i] == 1 && i < disS_tmSmall_beg) cnt_CBxp++;
		}
		cout << cnt_CBxp;
	}
	return 0;
} 
