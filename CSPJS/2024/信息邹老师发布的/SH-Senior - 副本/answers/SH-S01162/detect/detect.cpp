#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+10;
int n, m, L, V, l[N], r[N], cnt, nowr, dp[N], p[N], cnt2;
int sk[N];

struct Node{
	int l, r;
}x[N], s[N];

bool cmp(Node x,Node y){
	return x.r < y.r;
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> L >> V;
		cnt = 0;
		cnt2 = 0;
		for(int i = 1; i <= n; i++){
			l[i] = r[i] = -1;
			int d, v, a;
			cin >> d >> v >> a;
			if(a < 0){
				int x = abs(a);
				if(v <= V) continue;
				double tx = 1.0*(v-V)/x;
				double len = v*tx + a*tx*tx/2;
				l[i] = d;
				r[i] = min(1.0*L,d+len);
				int lenc = r[i]-d;
				if(sqrt(v*v+2.0*a*lenc) <= V) r[i]--;
			}
			if(a == 0){
				if(v <= V) continue;
				l[i] = d, r[i] = L;
			}
			if(a > 0){
				if(v > V){
					l[i] = d, r[i] = L;
					continue;
				}
				double tx = 1.0*(V-v)/a;
				double len = v*tx+a*tx*tx/2;
				l[i] = d+len+1;
				r[i] = L;
				int lenc = l[i]-d;
				if(sqrt(v*v+2.0*a*lenc) <= V) l[i]++;
			}
		}
		for(int i = 1; i <= n; i++){
			if(l[i] == -1 || l[i] > r[i]) continue;
			x[++cnt].l = l[i], x[cnt].r = r[i];
		}
		sort(x+1,x+cnt+1,cmp);
		nowr = 1;
		int ans1 = 0;
		for(int i = 1; i <= m; i++){
			cin >> p[i];
			while(nowr <= cnt && x[nowr].r < p[i]){
				if(x[nowr].l <= p[i-1]) {
					ans1++;
					s[++cnt2] = x[nowr];
				}
				++nowr;
			}
		}
		while(nowr <= cnt){
			if(x[nowr].l <= p[m]){
				ans1++;
				s[++cnt2] = x[nowr];
			}
			++nowr;
		}
		cout << ans1 << " ";
		nowr = 1;
		int lx = 0, lp = 0, rp = 0;
		sort(s+1,s+cnt2+1,cmp);
		for(int i = 1; i <= m; i++){
			while(nowr <= cnt2 && s[nowr].r < p[i]){
				lx = max(lx,s[nowr].l);
				nowr++;
			}
			while(p[sk[lp]] < lx) ++lp;
			dp[i] = dp[sk[lp]]+1;
			while(rp >= lp && dp[sk[rp]] >= dp[i]) --rp;
			sk[++rp] = i;
		}
		while(nowr <= cnt2){
			lx = max(lx,s[nowr].l);
			nowr++;
		}
		while(p[sk[lp]] < lx) ++lp;
		cout << m-dp[sk[lp]] << "\n";
	}
}
