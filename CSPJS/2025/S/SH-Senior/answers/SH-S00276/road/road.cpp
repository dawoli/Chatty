#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,ans,c,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> u >> v >> w;
		ans+=w;
	}
	for (int i=1;i<=k;i++){
		cin >> c;
		for (int j=1;j<=n;j++){
			cin >> a;
		}
	}
	cout << ans;
	return 0;
}
