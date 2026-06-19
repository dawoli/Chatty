#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int T;
int n, m, L, V;
int p[N], mxpos;
struct car{
	int d, v, a, mxv;
	int nearest, farthest;
}x[N];
bool all_zero = true, all_above = true;
void solve_zero(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(x[i].v > V && x[i].d <= p[m])
			ans++;
	}
	int tot = m - 1;
	if(ans == 0)
		tot = m;
	printf("%d %d\n", ans, tot);
}
void do_max(int pos){
	double vs = x[pos].v, aa = x[pos].a, ss = p[m] - x[pos].d;
	double ve = sqrt(vs * vs + 2 * aa * ss);
	int xx = ceil(ve);
	x[pos].mxv = xx;
}
void go_find_plus(int pos){
	if(x[pos].mxv < V){
		x[pos].nearest = m + 1;
//		cout << pos << " : " << m + 1 <<" " << 1 << " " << 2 << " " << 3 << endl;
		return;
	}
	long double vs = x[pos].v, aa = x[pos].a, ve = V;
	long double ss = (ve * ve) / (2.0 * aa) - (vs * vs) / (2.0 * aa);
	int dis = ceil(ss);
	if(dis < 0){
		dis = 0;
		ss = 0;
	}
	dis += x[pos].d;
	int fnd = lower_bound(p + 1, p + m + 1, dis) - p;
//	if(p[fnd] == dis + x[pos].d && dis != ss)
//		fnd++;
	if(dis >= p[m] && dis - x[pos].d > ss)
		fnd = m + 1;
	x[pos].nearest = fnd;
	x[pos].farthest = m;
	long double vn = sqrt(vs * vs + 2 * aa * (dis - x[pos].d));
	if(vn < V)
		x[pos].nearest = m + 1;
//	cout << pos << " : " << fnd << " " << dis << " " << p[fnd] << " " << x[pos].mxv << endl;
//	if(T == 1){
//		if(vn < V)
//			cout << pos << endl;;

//	}
}
void go_find_minus(int pos){
	double vs = x[pos].v, aa = x[pos].a, ve = V;
	double ss = (ve * ve - vs * vs) / (2 * aa);
	int dis = floor(ss);
	if(dis < 0){
		x[pos].nearest = m + 1;
		return;
	}
//	cout << x[pos].d + dis << endl;
	int fnd = lower_bound(p + 1, p + m + 1, x[pos].d + dis) - p;
	if(p[fnd] == dis + x[pos].d && dis != ss){
		fnd--;
		if(p[fnd] < x[pos].d || fnd == 0){
			x[pos].farthest = m + 1;
			return;
		}
	}
	x[pos].farthest = fnd;
	fnd = lower_bound(p + 1, p + m + 1, x[pos].d) - p;
	if(p[fnd] >= x[pos].d && p[fnd] <= x[pos].d + dis)
		x[pos].nearest = fnd;
	else
		x[pos].nearest = m + 1;
}
void solve(){
	int ans = 0;
//	cout << L << " " << V << " " << m << endl;
	for(int i = 1; i <= n; i++){
		if(x[i].a > 0){
			do_max(i);
			go_find_plus(i);
		}
		else{
			x[i].mxv = x[i].v;
			go_find_minus(i);
		}
		if(x[i].nearest < m + 1)
			ans++;
//		cout << i << " : " << x[i].mxv << " " << p[x[i].nearest] << endl;
	}
	printf("%d ", ans);
	int cnt = 0;
	if(all_above){
		if(ans == 0)
			cnt = m;
		else
			cnt = m - 1;
		printf("%d\n", cnt);
	}
}
bool tk[25];
int CNT, TOT;
int CCCCC;
void godo(){
//	CCCCC++;
	int tot = 0;
	int sum = 0;
	for(int i = 1; i <= m; i++)
		sum += tk[i];
//	for(int i = 1; i <= m; i++)
//		cout << tk[i];
//	cout << endl;
//	if(sum == 3){
//		for(int i = 1; i <= m; i++)
//			if(tk[i]) cout << i << " : " << p[i] << endl;
//	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!tk[j])
				continue;
			if(p[j] < x[i].d)
				continue;
			int tmp1 = V * V;
			int tmp2 = x[i].v * x[i].v + 2 * x[i].a * (p[j] - x[i].d);
//				if(sum == 3)
//					cout << i << " " << j << " : " << tmp1 << " " << tmp2 << endl;
			if(V * V < x[i].v * x[i].v + 2 * x[i].a * (p[j] - x[i].d)){
				tot++;
				break;
			}
		}
	}
	
	if(tot == TOT){
		CNT = max(CNT, m - sum);
	}
}
void dfs(int ps){
	if(ps == m + 1){
		godo();
		return;
	}
	tk[ps] = 1;
	dfs(ps + 1);
	tk[ps] = 0;
	dfs(ps + 1);
}
void solveBF(){
	int tot = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			tk[j] = 0;
//			cout << i << " : " << p[j] << " " << x[i].d << endl;;
			if(p[j] < x[i].d)
				continue;
//			if(p[j] == x[i].d){
//				if(x[i].v > V){
//					tot++;
//					break;
//				}
//				continue;
//			}
			int tmp1 = V * V;
			int tmp2 = x[i].v * x[i].v + 2 * x[i].a * (p[j] - x[i].d);
//			cout << i << " : " << tmp1 << " " << tmp2 << endl;
			if(tmp1 < tmp2){
				tot++;
				break;
			}
		}
	}
	printf("%d ", tot);
	TOT = tot;
	CNT = 0;
//	CCCCC=0;
	dfs(1);
	printf("%d\n", CNT);
//	cout << CCCCC << endl;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while(T > 0){
		T--;
		all_zero = true;
		all_above = true;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &x[i].d, &x[i].v, &x[i].a);
			if(x[i].a)
				all_zero = false;
			if(x[i].a < 0)
				all_above = false;
		}
		for(int i = 1; i <= m; i++){
			scanf("%d", &p[i]);
//			cin >> p[i];
//			cout << i << " : " << p[i] << endl;
		}
		p[m + 1] = 0;
		if(all_zero){
			solve_zero();
		}
		else if(n <= 20 && m <= 20){
//			cout << "here!\n";
			solveBF();
		}
		else{
			solve();
		}
	}
	return 0;
}
/*
10 7
10 6
9 6
10 6
9 7
9 7
9 8
10 6
10 8
9 6
9 7
10 8
8 7
10 6
10 7
9 7
9 7
9 7
9 7
9 8

2996 863
2994 285
2991 292
2995 2880
2982 2137
2999 2680
2995 2540
2986 1457
2929 1919
2997 2547
99691 35478
99987 68384
99335 81601
98570 49067
100000 88807
99990 35942
99900 65610
99981 44819
99999 18514
99955 92874

*/
