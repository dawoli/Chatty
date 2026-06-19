#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m, k;
int u, v, w;
int c, a;
int allow[100];
int f[10010];

int get_x(int x){
	if(x == f[x])return x;
	if(x == 0)return 0;
	return get_x(f[x]);
}

struct rode{
	int u, v, w;
};

struct pos{
	int u, w;
};

pos tmp[10010];

struct village{
	int c, ind;
	pos a[10010];
};

vector <rode> rodes;
vector <village> vill;

rode create(int u, int v, int w){
	rode t;t.u = u;t.v = v;t.w = w;return t;
}

bool cmp(pos l, pos r){
	return l.w < r.w;
}

bool cmpr(rode l, rode r){
	return l.w < r.w;
}
/*int solve(){
	memset(f, 0, sizeof(f));
	int ans = 0;
	int cur_r = 1;
	while(1){
		bool ff = 0;
		for(int i = 1; i <= n; i ++){
			if(f[i] == 0){
				ff = 1;break;
			}
		}
		if(!f)break;
		
		rode minr;
		minr.u =  rodes[cur_r].u;
		minr.v = rodes[cur_r].v;
		minr.w = rodes[cur_r ++].w;
		
		for(auto vi : vill){
			int tw = vi.c + vi.a[1].w + vi.a[2].w;
			if(allow[vi.ind] == 0 && tw < minr.w){
				allow[vi.ind] = 1;
				return -1;
			}
		}
		int vu, vv, vw = 1000000000;
		for(auto vi : vill){
			if(allow[vi.ind]){
				u = -1;
				for(int i = 1; i <= n; i ++){
					if(f[i] == 0){
						u = i;
					}
				}
				v = -1;
				for(int i = 1; i <= n; i ++){
					if(f[i] != 0 && i != u){
						v = i;
					}
				}
				w = vi.a[u].w + vi.a[v].w;
				int gv = get_x(v), gu = get_x(u);
				if(((gu == 0 ||gv == 0) || (gu != gv)) && w < vw){
					vw = w;
					vv = v;
					vu = u;
				}
			}
		}
		if(minr <= vw){
			int gv = get_x(minr.v), gu = get_x(minr.u);
			if(gu == 0 || gv == 0 || gu != gv){
				if(gu == 0 &&gv == 0){
					f[v] = v;
					f[u] = v;
				}
				else if(gu == 0)f[u] = v;
				else if(gv == 0)f[v] = u;
				else if(gu != gv){
					f[u] = v; 
				} 
			}
			
		}
	}
}*/

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		scanf("%d%d%d", &u, &v, &w);
		rodes.push_back(create(u, v, w));
	}
	for(int i = 1; i <= k; i ++){
		scanf("%d", &c);
		village t;
		t.c = c;
		t.ind = i;
		for(int i = 1; i <= n; i ++){
			scanf("%d", &a);
			pos p;
			p.u = i;
			p.w = a;
			tmp[i] = p;
		}
		sort(tmp + 1, tmp + n + 1, cmp);
		for(int i = 1; i <= n; i ++)t.a[i] = tmp[i];
		vill.push_back(t);
	}
	sort(rodes.begin(), rodes.end(), cmpr);
	int ans = 0;
	for(int i = 1; i <= n - 1; i ++){
		ans += rodes.back().w;
		rodes.pop_back();
	}
	cout << ans << endl;
	return 0;
}
