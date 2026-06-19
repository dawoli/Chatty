#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char c[1010][1010];
bool f[1010][1010];
long long ans;
int d1[10] = {0,1,0,-1};
int d2[10] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		ans = 0;
		memset(f,0,sizeof(f));
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= m;k++){
				cin >> c[j][k];
			}
		}
		for(int j = 1;j <= k + 1;j++){
			if(!f[x][y]){
				f[x][y] = 1;
				ans++;
			}
			if(x + d1[d] < 1 || x +d1[d] > n ||y + d2[d] < 1 || y + d2[d] >m || c[x + d1[d]][y + d2[d]] == 'x'){
				d = d + 1;
				d %= 4;
				continue;
			}
			else{
				x = x + d1[d];
				y = y + d2[d];
			}
			
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
