#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,m,l,V,cnt,ans=-0x3f3f3f3f;
int a[maxn],d[maxn],v[maxn],p[maxn];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while (t -- ) {
		cin >> n >> m >> l >> V;
		for (int i = 1 ; i <= n ; i ++ )	cin >> d[i] >> v[i] >> a[i];
		for (int i = 1 ; i <= m ; i ++ )	cin >> p[i];
		for (int i = 1 ; i <= n ; i ++ )	if(v[i] >= V)	cnt ++;
		ans = max(n - 1,ans);
	}
	cout << cnt << " " << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
