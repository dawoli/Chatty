#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

int t, n, m, l, V, ans = 0, ans2 = 0;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
bool flag[100005];
bool b[100005];

struct PPlace{
	int l, r;
	bool operator > (const PPlace x) const {return l > x.l;}
};

int get_int(double x){
	int idx = 0;
	while(idx <= x){
		idx++;
	}
	if(x == idx) return idx;
	else return idx - 1;
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--){
		priority_queue<PPlace, vector<PPlace>, greater<PPlace> > c;
		vector<PPlace> plac;
		memset(flag, false, sizeof(flag));
		cin >> n >> m >> l >> V;
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
		}
		for(int i = 0; i < m; i++){
			scanf("%d", &p[i]);
		}
		
		ans = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(p[i] < d[j]) continue;
				if(flag[j] == true) continue;
				int nv = v[j] * v[j] + 2 * a[j] * (p[i] - d[j]);
				double sqnv = sqrt(nv);
				if(sqnv > V && flag[j] == false){
					ans++;
					b[j] = true;
					flag[j] = true;
				} 
			}
		}
		
		for(int i = 0; i < n; i++){
			if(b[i] == false) continue;
			PPlace place;
			// int nsshangmian = V * V - v[i] * v[i];
			// int nsxiamian = 2 * a[i];
			if(a[i] == 0){
				place.l = d[i];
				place.r = l;
				c.push(place);
				continue;
			}
			int ns = double((V * V - v[i] * v[i]) / (2 * a[i]));
			int r_p = d[i] + ns;
			if(a[i] >= 0){
				place.l = r_p;
				place.r = l;
			}
			else{
				place.l = d[i];
				place.r = r_p;
			}
			c.push(place); 
		}
		
		while(!c.empty()){
			PPlace cpl = c.top();
			c.pop();
			PPlace cpr = c.top();
			c.pop();
			if(cpl.r < cpr.r && cpr.l < cpl.r){
				PPlace place;
				place.l = cpr.l;
				place.r = cpl.r;
				c.push(place);
			}
			else if(cpl.r >= cpr.r){
				c.push(cpr);
			}
			else{
				plac.push_back(cpl);
				c.push(cpr);
			}
			if(c.size() == 1){
				PPlace cpp = c.top();
				plac.push_back(cpp);
				break;
			}
		}
		
		sort(p, p + m);
		ans2 = 0;
		
		int siz = plac.size();
		for(int i = 0; i < siz; i++){
			for(int j = 0; j < m; j++){
				if(p[j] >= plac[i].l && p[j] <= plac[i].r){
					ans2++;
					break;
				}
			}
		}
		
		cout << ans << ' ' << m - ans2 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
