#include <bits/stdc++.h>
using namespace std;
int T,n,a[100010],vis[100010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while (T--){
		memset(vis,0x3f,sizeof(vis));
		int ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) cin >> a[i];
		for (int i = n;i >= 1;i--){
			for (int j = 1;j <= n;j++){
				if (i != j && a[i] == a[j] && vis[i] != 0 & vis[j] != 0){
					ans += a[i];
					vis[i] = 0;
					vis[j] = 0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
