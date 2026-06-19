#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d[100005],v[100005],a[100005],p[100005],ans,flag;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		flag = 1;
		cin >> n >> m >> l >> V;
		for(int i = 1;i<=n;i++){
			cin >> d[i] >> v[i] >> a[i];
			if(a[i]<0) flag = 0;
		}
		for(int i = 1;i<=m;i++) cin >> p[i];
		for(int i = 1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]) ans++;
			}
			else if(a[i]>0){
				if(d[i]+max(0,(V*V-v[i]*v[i])/(2*a[i]))<p[m]) ans++;
			}
		}
		cout << ans << ' ';
		if(flag==1){
			if(ans==0) cout << m;
			else cout << m-1;
		}
	}
	return 0;
}
