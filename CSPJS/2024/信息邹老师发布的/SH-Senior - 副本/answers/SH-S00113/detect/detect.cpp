#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int T,n,m,l,vv,d[100005],v[100005],a[100005],p,lp=0,ans=0;
	cin >> T;
	while(T--){
	    cin >> n >> m >> l >> vv;
	    lp=0,ans=0;
	    for(int i=1;i<=n;i++) cin >> d[i] >> v[i] >> a[i];
	    for(int i=1;i<=m;i++){
	    	cin >> p;
	    	lp=max(lp,p);
	    }
	    for(int i=1;i<=n;i++) if(d[i]<=lp&&v[i]>vv) ans++;
	    cout << ans << ' ' << (ans==0?m:m-1) << endl;
	}
	return 0;
}
