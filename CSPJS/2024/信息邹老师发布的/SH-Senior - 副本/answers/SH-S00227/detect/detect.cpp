#include<bits/stdc++.h>
using namespace std;
#define N 100009
int n,m,L,V,k,p[N],d[N];
struct range{ int l,r; } x[N];
bool cmp(range a,range b){ return a.r < b.r; }
void input(){
	scanf("%d %d %d %d",&n,&m,&L,&V);
	for(int i = 1;i <= n;i++){
		int pos,v1,v2;
		scanf("%d %d %d",&pos,&v1,&v2);
		x[i] = {-1,-1};
		long long l,r;
		if(v1 > V && v2 >= 0){ x[i] = {pos,L}; continue; }
		if(v1 <= V && v2 <= 0) continue;
		double tmp = (1ll * V * V - 1ll * v1 * v1) / 2.0 / v2;
		if(v2 >= 0){
			l = floor(pos + tmp) + 1,r = L;
			if(l > L) continue;
		}else{
			l = pos,r = ceil(pos + tmp) - 1;
			if(r > L) r = L;
		}
		x[i] = {l,r};
	}
	for(int i = 1;i <= m;i++) scanf("%d",&p[i]);
	sort(p + 1,p + m + 1);
}
void solve(){
	sort(x + 1,x + n + 1,cmp);
	int ans1 = 0,ans2 = 0,lst = -1;
	for(int i = 1;i <= n;i++){
		if(x[i].l == -1 && x[i].r == -1) continue;
		int id = upper_bound(p + 1,p + m + 1,x[i].r) - p - 1;
		if(p[id] >= x[i].l){
			ans1++;
			if(lst < x[i].l){
				ans2++;
				lst = p[id];
			}
		}
	}
	printf("%d %d\n",ans1,m - ans2);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		input(); solve();
	}
	return 0;
}

