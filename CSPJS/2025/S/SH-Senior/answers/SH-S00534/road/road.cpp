#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MXN = 1e4+5;
const int MXM = 1e6+5;
int n, m, k;
int ui, vi, wi;
LL ans;
int ki;
bool havezero; 
int zeronum;

int fa[MXN], h[MXN];
int kc[15];
int ka[15][MXN];

int find(int x){
	if (x == fa[x]){
		return x;
	}
	return fa[x] = find(fa[x]);
}

void unio(int x, int y){
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty){
		return;
	}
	if (h[rootx] > h[rooty]){
		fa[rooty] = rootx;
	}
	if (h[rootx] < h[rooty]){
		fa[rootx] = rooty;
	}
	if (h[rootx] == h[rooty]){
		fa[rootx] = rooty;
		h[rooty]++;
	}
}

struct edge{
	int frm, to, w;
	bool operator <(const edge& a)const {
		return a.w < w;
	}
}E[MXM];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	priority_queue<edge> pq;
	havezero = false;
	for (int i = 1; i <= m; i++){
		cin>>ui>>vi>>wi;
		E[i] = {ui, vi, wi};
		pq.push(E[i]);
	}
	for (int i = 1; i <= k; i++){
		cin>>kc[i];
		if (kc[i] == 0){
			havezero = true;
			zeronum = i;
		}
		for (int j = 1; j <= n; j++){
			cin>>ka[i][j];
		}
	}
	//1~4
	if (k == 0){
		for (int i = 1; i <= m; i++){
			pq.push(E[i]);
		}
		for (int i = 1; i <= n; i++){
			fa[i] = i;
		}
		while (!pq.empty()){
			int vf, vt, vw;
			vf = pq.top().frm;
			vt = pq.top().to;
			vw = pq.top().w;
			pq.pop();
			if (find(vf) == find(vt)){
				continue;
			}
			unio(vf, vt);
			ans += vw;
		}
		cout<<ans;
		return 0;
	}
	if (havezero == true){
		for (int i = 1; i <= m; i++){
			pq.push(E[i]);
			edge nw;
			nw.frm = n+1;
			nw.to = i;
		}
		for (int i = 1; i <= n; i++){
			fa[i] = i;
		}
		while (!pq.empty()){
			int vf, vt, vw;
			vf = pq.top().frm;
			vt = pq.top().to;
			vw = pq.top().w;
			pq.pop();
			if (find(vf) == find(vt)){
				continue;
			}
			unio(vf, vt);
			ans += vw;
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
