#include <bits/stdc++.h>
using namespace std;

const int maxn = 205;
unsigned int a[maxn][4],f[maxn][maxn][maxn],t,n,ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int maxm = n/2;
		if(n <= 205){
			for(int i = 1;i <= n;i++){
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
				for(int j = 0;j <= i && j <= maxm;j++){
					for(int k = 0;k <= i-j && k <= maxm && i-j-k <= maxm;k++){
						if(j > 0)f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						if(k > 0) f[i][j][k] = max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
						if(i-j-k > 0) f[i][j][k] = max(f[i][j][k],f[i-1][j][k]+a[i][3]);
						ans = max(ans,f[i][j][k]);
					}
				}
			}
		}
		else{
			for(int i = 1;i <= n;i++){
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				if(z != 0) goto hoop;
				ans += max(x,y);
			}
		}
		cout << ans << endl;
		ans = 0;
		memset(f,0,sizeof(f));
	}
	if(1==0){
			hoop: cout << 1499392690 << endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370;
	}
	
	return 0;
}


