#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f * x;
}

struct car{
	int d, v, a;
};

int t, n, m, L, v, res;
const int maxn = 1e5 + 10;
int p[maxn];
car c[maxn];
int l[maxn], r[maxn];
int fa[maxn];
set<int> need;

void init(){
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
}

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]); 
}

bool merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx == fy) return false;
	fa[fx] = fy;
	return true;
}

signed main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	t = read();
	while(t--){
		
		n = read(), m = read(), L = read(), v = read();
		init();
		for(int i = 1; i <= n; i++){
			int d = read(), v = read(), a = read();
			c[i] = {d, v, a};
		}
		for(int i = 1; i <= m; i++) p[i] = read();
		for(int i = 1; i <= n; i++){
			if(c[i].a == 0){
				if(c[i].v > v){
					res++;
					int k = 1;
						while(p[k] < c[i].d){
							k++;
						}
					l[i] = p[k], r[i] = p[m];
				}
				continue;
			}
			if(c[i].a > 0){
				double s = (v * v - c[i].v * c[i].v) / (2 * c[i].a) + c[i].d; //超速位置
				for(int j = 1; j <= m; j++){
					if(p[j] < c[i].d) continue;
					if(p[j] > s){
						res++;
						l[i] = p[j], r[i] = p[m];
						break;
					}
				}
			}
			if(c[i].a < 0){
				double s = (v * v - c[i].v * c[i].v) / (2 * c[i].a) + c[i].d; //超速位置
				for(int j = 1; j <= m; j++){
					if(p[j] < c[i].d) continue;
					if(p[j] < s){
						res++;
						int k = j;
						while(p[k] >= c[i].d){
							k--;
						}
						k++;
						l[i] = p[k], r[i] = p[j];
						break;
					}
				}
			}
		}
		cout << res << " ";
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if((l[i] <= l[j] && r[i] >= r[j]) || (l[i] >= l[j] && r[i] <= r[j])) merge(i, j); 
			}
		}
		cout << endl;
		for(int i = 1; i <= n; i++){
			need.insert(fa[i]);
			cout << l[i] << " " << r[i] << " " << fa[i] << endl;
		}
		cout << need.size() << '\n';
	}
	
	return 0;
}

//double s = (v * v - c[i].v * c[i].v) / (2 * c[i].a) + c[i].d; //超速位置
