#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V,p[100010];
struct car{
	int d,v,a;
}c[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while (T--){
		int ans = 0,res = 0;
		cin >> n >> m >> L >> V;
		for (int i = 1;i <= n;i++){
			cin >> c[i].d >> c[i].v >> c[i].a;	
		}
		for (int i = 1;i <= m;i++){
			cin >> p[i];
		}
		for (int i = 1;i <= n;i++){
			if(c[i].v > V && c[i].d <= p[m]){
				ans++;
				for (int j = 1;j <= m;j++){
					if (c[i].d > p[j]) res++;
				}
			}
		}
		cout << ans << " " << res << endl;
	}
	return 0;
}
