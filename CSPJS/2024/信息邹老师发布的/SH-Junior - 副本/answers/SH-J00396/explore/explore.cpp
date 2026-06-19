#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int T;
char mp[N][N];
int vis[N][N];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool canmove(int x,int y,int d,int n,int m){
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] == '.') return 1;
	else return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for (int c = 1;c <= T;c++){
		int n,m,k,xx,yy,dd;
		int ans = 0;
		cin>>n>>m>>k;
		cin>>xx>>yy>>dd;
		vis[xx][yy] = c;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				cin>>mp[i][j];
			}
		}
		for (int i = 1;i <= k;i++){
			if (canmove(xx,yy,dd,n,m)){
				xx = xx + dx[dd];
				yy = yy + dy[dd];
				vis[xx][yy] = c;
			}else{
				dd += 1;
				dd %= 4;
			}
		}
		
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				if (vis[i][j] == c)
					ans++; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
