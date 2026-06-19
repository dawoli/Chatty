#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int T,n,m,L,V;
int d[100010],v[100010],a[100010],p[100010];
struct node{
	int l,r;
	bool operator <(const node& kkk)const{
		return r < kkk.r;
	}
}tmp[100010];
int tot = 0;
bool check(int id,int s){
	return v[id] * v[id] + 2 * a[id] * s > V * V;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T = read();
	while(T--){
		n = read(),m = read(),L = read(),V = read();
		for(int i = 1; i <= n; i++) d[i] = read(),v[i] = read(),a[i] = read();
		for(int i = 1; i <= m; i++) p[i] = read();
		tot = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				if(v[i] > V){
					int l = d[i],r = L;
					if(l > p[m] || r < p[1]) continue;
					int lid = lower_bound(p + 1,p + m + 1,l) - p;
					int rid = upper_bound(p + 1,p + m + 1,r) - p - 1;
					if(lid > m || rid < 1 || lid > rid) continue;
					tmp[++tot] = (node){lid,rid};
				}
			}
			else if(a[i] > 0){
				int ll = 0,rr = L - d[i];
				if(!check(i,rr)) continue;
				while(ll < rr){
					int mid = (ll + rr) >> 1;
					if(check(i,mid)) rr = mid;
					else ll = mid + 1;
				}
				int l = d[i] + ll,r = L;
				if(l > p[m] || r < p[1]) continue;
				int lid = lower_bound(p + 1,p + m + 1,l) - p;
				int rid = upper_bound(p + 1,p + m + 1,r) - p - 1;
				if(lid > m || rid < 1 || lid > rid) continue;
				tmp[++tot] = (node){lid,rid};
			}
			else{
				int ll = 0,rr = L - d[i];
				if(!check(i,ll)) continue;
				while(ll < rr){
					int mid = (ll + rr + 1) >> 1;
					if(check(i,mid)) ll = mid;
					else rr = mid - 1;
				}
				int l = d[i],r = d[i] + ll;
				if(l > p[m] || r < p[1]) continue;
				int lid = lower_bound(p + 1,p + m + 1,l) - p;
				int rid = upper_bound(p + 1,p + m + 1,r) - p - 1;
				if(lid > m || rid < 1 || lid > rid) continue;
				tmp[++tot] = (node){lid,rid};
			}
		}
		printf("%lld ",tot);
		sort(tmp + 1,tmp + tot + 1);
		int ans = 0,tmpr = -1;
		for(int i = 1; i <= tot; i++){
			if(tmp[i].l <= tmpr && tmpr <= tmp[i].r) continue;
			tmpr = tmp[i].r,ans++;
		}
		printf("%lld\n",m - ans);
	}
	return 0;
}
