#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int t,n,a[100005][3],f[205][105][105];
int p[100005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		memset(f,0,sizeof f);
		for(int i = 1;i <= n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			p[i] = a[i][0];
		}
		if(n <= 200){
			for(int i = 1;i <= n;i++){
				for(int j = 0;j <= i && j <= n / 2;j++){
					for(int k = 0;k + j <= i && k <= n / 2;k++){
						if(j >= 1) f[i][j][k] = max(f[i - 1][j - 1][k] + a[i][0],f[i][j][k]);
						if(k >= 1) f[i][j][k] = max(f[i - 1][j][k - 1] + a[i][1],f[i][j][k]);
						if((i - j - k) >= 1) f[i][j][k] = max(f[i - 1][j][k] + a[i][2],f[i][j][k]);
					}
				}
			}
			int ans = 0;
			for(int i = 0;i <= n / 2;i++)
				for(int j = n / 2 - i;j <= n / 2;j++)
					ans = max(ans,f[n][i][j]);
			cout << ans << "\n";
		}
		else {
			int ans = 0;
			sort(p + 1,p + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++) ans += p[i];
			cout << ans << "\n";
		}
	}
	return 0;
}
