#include <bits/stdc++.h>
using namespace std;
#define int long long 
int d[100005],vc[100005],a[100005],p[100005];
bool vis[100005];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int q; cin >> q;
	while(q --){
		int ans = 0,cnt = 0;
		memset(vis,0,sizeof(vis));
		int n,m,l,v; cin >> n >> m >> l >> v;
		for(int i = 1; i <= n; ++ i){
			cin >> d[i] >> vc[i] >> a[i];
		}
		for(int j = 1; j <= m; ++ j){
			cin >> p[j];
		}
		for(int i = 1; i <= n; ++ i){
			int s;
			if(a < 0) s = lower_bound(p + 1, p + m + 1,d[i]) - p ; 
			if(a >= 0) s = m;
			
			if(vc[i]*vc[i] + 2*a[i]*(p[s] - l)- v*v > 0){
				ans ++;
				if(!vis[s]){
				    cnt ++; vis[s] = 1;
			    }
			}
		}
        cout << ans << " " << m - cnt - 1 << endl;
        //for(int i = 1; i <= m; ++ i) cout << vis[i] << endl;
	}
}
