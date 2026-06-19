#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int l,r,v;
}e[1200010];
bool cmp(edge x,edge y){
	return x.v < y.v;
}
int n,m,k,cnt,id[20010],ans = 1e18,a[20][10010],c[20],l[1000010],r[1000010],v[1000010];bool ok = 1;
int root(int x){
	return (id[x] == x?x:id[x] = root(id[x]));
}
void solve(int x){
	sort(e + 1,e + cnt + 1,cmp);
	int sum = x;
	for(int i = 1;i <= n + k;i++) id[i] = i;
	for(int i = 1;i <= cnt;i++){
		int rl = root(e[i].l),rr = root(e[i].r);
		if(rl != rr){
			sum += e[i].v;
			if(sum >= ans) return ;
			id[rl] = rr;
		}
	}
	ans = sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> l[i] >> r[i] >> v[i];
		e[i].l = l[i],e[i].r = r[i],e[i].v = v[i];
	}
	for(int i = 0;i < k;i++){
		cin >> c[i];
		bool o = 0;
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(!a[i][j]) o = 1;
		}
		if(!o) ok = 0;
	}
	for(int i = 0;i < (1 << k);i++){
		if(m * log(m) / log(2) * (i + 1) >= 6e7 || ok) i = (1 << k) - 1;
		cnt = m;int s = 0;
		for(int j = 1;j <= m;j++) e[j].l = l[j],e[j].r = r[j],e[j].v = v[j];
		for(int j = 0;j < k;j++){
			if((i >> j) & 1){
				s += c[j];
				for(int o = 1;o <= n;o++){
					cnt++;
					e[cnt].l = j + n + 1,e[cnt].r = o,e[cnt].v = a[j][o];
				}
			}
		}
		solve(s);
	}
	cout << ans;
	return 0;
}
