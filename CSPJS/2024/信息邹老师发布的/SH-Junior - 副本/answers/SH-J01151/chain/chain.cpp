#include<bits/stdc++.h>
using namespace std;

const int R = 1e2+10, N = 1e5+10, L = 2e5+10;
int n, k, q, len[N], lx[N], rx[N], cnt, cntg, vp[N];
int vx[L], fr[L], d[L];
bool vis[L], visv[L], visx[L], ans[N];
struct Node{
	int v, fr;
};
int vnxt[L], hdv[L], stp[L], edp[L], nxt2[L], hd2[L];
Node vval[L];
void adg(int v, int pos, int fr){
	vnxt[++cntg] = hdv[v];
	hdv[v] = cntg;
	vval[cntg] = (Node){pos,fr};
	nxt2[cntg] = hd2[vnxt[cntg]];
	if(vval[vnxt[cntg]].fr != fr){
		nxt2[cntg] = vnxt[cntg];
		hd2[cntg] = cntg;
	}
}

struct query{
	int r, c, h;
}qe[N];

bool cmp(query x,query y){
	return x.r < y.r;
}

inline void push(){
	memset(visx,0,sizeof(visx)); 
	for(int i = 1; i <= cnt; ++i)
		if(vis[i]){
			visv[vx[i]] = false;
			int v = vx[i];
			if(!visx[v]){
				for(int j = hdv[v]; j != 0; j = vnxt[j]){
					if(vval[j].fr == fr[i]){
						stp[v] = j;
						edp[v] = vnxt[nxt2[j]];
						j = nxt2[j];
					} else {
						++d[vval[j].v+1], --d[min(rx[vval[j].fr]+1,vval[j].v+k)];
					}
				}
				visx[v] = true;
			} else {
				if(vval[stp[v]].fr == fr[i]) continue;
				for(int j = stp[v]; j != edp[v]; j = vnxt[j])
					++d[vval[j].v+1], --d[min(rx[vval[j].fr]+1,vval[j].v+k)];
				stp[v] = edp[v] = 0;
			}
		}
	int now = 0;
	for(int i = 1; i <= cnt; ++i){
		now += d[i];
		if(now > 0){
			vis[i] = true;
			visv[vx[i]] = true;
		} else {
			vis[i] = false;
		}
		d[i] = 0;
	}
	d[cnt+1] = 0;
}

signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		visv[1] = true;
		cnt = 0;
		cntg = 0;
		cin >> n >> k >> q;
		for(int i = 1; i <= n; ++i){
			cin >> len[i];
			lx[i] = cnt+1;
			for(int j = 1; j <= len[i]; ++j){
				cin >> vx[++cnt];
				fr[cnt] = i;
				adg(vx[cnt],cnt,i);
				if(vx[cnt] == 1) vis[cnt] = true;
			}
			rx[i] = cnt;
		}
		for(int i = 1; i <= q; ++i){
			cin >> qe[i].r >> qe[i].c;
			qe[i].h = i;
		}
		sort(qe+1,qe+q+1,cmp);
		int now = 0;
		for(int i = 1; i <= q; ++i){
			while(qe[i].r != now){
				push();
				now++;
			}
			ans[qe[i].h] = visv[qe[i].c];
		}
		for(int i = 1; i <= q; ++i) cout << ans[i] << "\n";
		for(int i = 1; i <= cnt; ++i) hdv[vx[i]] = 0;
		memset(vis,0,sizeof(vis));
		memset(visv,0,sizeof(visv));
		memset(visx,0,sizeof(visx));
	}
}
