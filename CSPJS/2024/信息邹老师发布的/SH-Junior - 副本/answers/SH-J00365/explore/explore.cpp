#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,d;
char s[1100][1100];
const int D[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
bool vis[1100][1100];
bool check(int x,int y){
	if(x < 1 || x > n) return false;
	if(y < 1 || y > m) return false;
	if(s[x][y] == 'x') return false;
	return true;
}
void solve(){
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d",&x,&y,&d);
	for(int i = 1;i <= n;i++){
		scanf("%s",s[i] + 1);
	}
	vis[x][y] = true;
	for(int i = 1;i <= k;i++){
		int next_x = x + D[d][0];
		int next_y = y + D[d][1];
		if(check(next_x,next_y)){
			vis[next_x][next_y] = true;
			x = next_x;		y = next_y;
		} else {
			d = (d + 1) % 4;
		}
	}
	int ans = 0; 
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			ans += vis[i][j];
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
