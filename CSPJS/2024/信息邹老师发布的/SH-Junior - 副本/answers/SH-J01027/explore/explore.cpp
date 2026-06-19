#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;

int T, n, m , k, botx, boty, botd, ans;
int detx, dety;
char a[N][N]; // [n][m]
bool vis[N][N];

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>botx>>boty>>botd;
		memset(vis, 0, sizeof(vis));  // 多组数据 
		ans = 1;
		vis[botx][boty] = 1;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin>>a[i][j];
			}
		}
		for(int i=1; i<=k; i++){
			if(botd == 0){
				detx = botx;
				dety = boty + 1;
			} else if(botd == 1){
				detx = botx + 1;
				dety = boty;
			} else if(botd == 2){
				detx = botx;
				dety = boty - 1;
			} else if(botd == 3){
				detx = botx - 1;
				dety = boty;
			}
			if(1 <= detx && detx <= n && 1 <= dety && dety <= m && a[detx][dety] == '.'){
				botx = detx;
				boty = dety;
				if(!vis[botx][boty]){
					vis[botx][boty] = 1;
					ans++;
				}
			} else {
				botd = (botd + 1) % 4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
