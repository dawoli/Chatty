#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int n, m, ln, vm;
vector <pair<int, int> > qj;
vector <pair<int, int> > b;
int p[100005];
vector <pair<int, int> > dt;
vector <pair<int, int> > c;
bool flg[100005] = {0};
bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.first!=y.first)
		return x.first<y.first;
	else
		return x.second > y.second;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		qj.clear();
		b.clear();
		dt.clear();
		c.clear();
		scanf("%d %d %d %d", &n, &m, &ln, &vm);
		for(int i = 1;i <= n;i++){
			int d, v, a, l, r;
			scanf("%d %d %d", &d, &v, &a);
			if(a > 0){
				if(v > vm){
					l = d;
				}else{
					int x = d+(vm*vm-v*v)/(2*a)+1;
					if(x > ln){
						l = ln+1;
					}else{
						l = x;
					}
				}
				r = ln;
			}else if(v <= vm){
				l = ln+1;
				r = ln;
			}else if(a == 0){
				l = d;
				r = ln;
			}else{
				int x = d+(vm*vm-v*v)/(2*a);
				if((v*v-vm*vm)%(-2*a) == 0)
					x--;
				if(x < d){
					l = ln+1;
					r = ln;
				}else{
					l = d;
					r = min(x, ln);
				}
			}
			if(l > r)
				continue;
			qj.push_back(make_pair(l, r));
		}
		sort(qj.begin(), qj.end());
		for(int i = 1;i <= m;i++){
			scanf("%d", &p[i]);
		}
		int pt = 1, as = 0;
		p[m+1] = ln+1;
		for(int i = 0;i < qj.size();i++){
			flg[i] = 0;
		}
		for(int i = 0;i < qj.size();i++){
			while(p[pt] < qj[i].first && pt <= m){
				pt++;
			}
			if(!(qj[i].second >= p[pt])){
				flg[i] = 1;
			}
			as += (qj[i].second >= p[pt]);
		}
		printf("%d ", as);
		int mn = ln+1;
		for(int i = qj.size()-1;i>=0;i--){
			if(flg[i])
				continue;
			if(qj[i].second >= mn){
				continue;
			}
			b.push_back(qj[i]);
			mn = min(mn, qj[i].second);
		}
		reverse(b.begin(), b.end());
		int w = b.size();
		b.push_back(make_pair(0, 0));
		pt = 0;
		for(int i = 1;i <= m;i++){
			while(b[pt].second < p[i] && pt < w){
				pt++;
			}
			dt.push_back(make_pair(pt, 0));
		}
		pt = 0;
		for(int i = 1;i <= m;i++){
			while(b[pt].first <= p[i] && pt < w){
				pt++;
			}
			dt[i-1].second = pt-1;
		}
		for(int i = 0;i < dt.size();i++){
			if(dt[i].first == w || dt[i].second == -1){
				dt[i] = make_pair(w, w);
			}
		}
		sort(dt.begin(), dt.end(), cmp);
		while(dt.size()){
			if(dt[dt.size()-1].first == w){
				dt.pop_back();
			}else{
				break;
			}
		}
		int mx = -1;
		for(int i = 0;i < dt.size();i++){
			if(dt[i].second <= mx){
				continue;
			}
			c.push_back(dt[i]);
			mx = max(mx, dt[i].second);
		}
		int ans = 0;
		mx = -10;
		int lst = -10;
		for(int i = 0;i < c.size();i++){
			if(c[i].first <= lst+1){
				if(c[i].second <= mx)
					continue;
				mx = max(c[i].second, mx);
			}else{
				if(mx > lst){
					ans++;
					lst = mx;
					i--;
					continue;
				}else{
					ans++;
					mx = lst = c[i].second;
				}
			}
		}
		if(mx > lst){
			ans++;
		}
		printf("%d\n", m-ans);
	}
	return 0;
}