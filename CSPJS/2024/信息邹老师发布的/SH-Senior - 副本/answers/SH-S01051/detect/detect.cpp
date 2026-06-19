#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long lld;
int T, n, m, L, l[N];
struct str{
	int pos, num;
}zt[N];
bool na[N];
lld V, d[N], v[N], a[N], p[N];
vector<int> ve[N];
vector<int> v2[N];
void init(){
	memset(l, 0, sizeof(l));
	memset(na, 0, sizeof(na));
	scanf("%d%d%d%lld", &n, &m, &L, &V);
	for(int i = 1;i <= n;i++){
		ve[i].clear();
		v2[i].clear();
		zt[i] = {i, 0};
	}
	for(int i = 1;i <= n;i++) scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
	for(int i = 1;i <= m;i++){
		scanf("%lld", &p[i]);
	}
}
void test_one(int i){
	int pos = d[i], ten = 1;
	lld disy = pos*2;
	for(int j = 1;;j++){
		lld disn = pos*2+v[i]*j*2+a[i]*(j*j-2*j+1);
		while(ten < m && p[ten]*2 < disy){
			ten++;
		}
		lld spd = v[i]*v[i] + 2*a[i]*(p[ten]-pos);
		if(a[i] < 0 && spd <= V*V) return;
		if(a[i] > 0 && spd > V*V){
			for(int k = ten;k <= m;k++){
				ve[i].push_back(k);
			}
			l[i] += m-ten+1;
			return;
		}
		while(disy <= p[ten]*2 && disn >= p[ten]*2){
			if(spd > V*V){
				l[i]++;
				ve[i].push_back(ten);
			}
			ten++;
		}
		if(disn >= L*2 || v[i]+j*a[i] <= 0) return;
		disy = disn;
	}
}
void link_tester(){
	for(int i = 1;i <= n;i++){
		test_one(i);
	}
}
bool cmp(str a, str b){
	return a.num <= b.num;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		init();
		link_tester();
		int ans = 0, ansb = 0;
		for(int i = 1;i <= n;i++){
			if(l[i]) ans++;
			if(l[i] == 1) na[ve[i][0]] = 1;
			for(int j = 0;j < l[i];j++){
				zt[ve[i][j]].num++;
				v2[ve[i][j]].push_back(i);
			}
		}
		sort(zt+1, zt+n+1, cmp);
		for(int i = 1;i <= n;i++){
			if(na[i]) continue;
			bool cand = 1;
			int sz = v2[i].size();
			for(int j = 0;j < sz;j++){
				if(l[v2[i][j]] == 1) cand = 0;
			}
			if(!cand) continue;
			for(int j = 0;j < sz;j++){
				if(l[v2[i][j]]) l[v2[i][j]]--;
			}
			ansb++;
		}
		printf("%d %d\n", ans, ansb);
	}
	return 0;
}
