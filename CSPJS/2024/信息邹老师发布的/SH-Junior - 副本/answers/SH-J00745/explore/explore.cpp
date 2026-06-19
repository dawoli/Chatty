#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		int cnt = 1;
		char G[1005][1005];
		bool vis[1005][1005] = {0};
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin>>G[i][j];
			}
		}
		vis[x][y] = 1;
		for(int i = 1;i <= k;i++){
			int xx = x + dx[d],yy = y + dy[d];
			if(xx >= 1 && yy >= 1 && xx <= n && yy <= m && G[xx][yy] != 'x'){
				if(vis[xx][yy]){
					x = xx;y = yy;
				}
				else{
					cnt++;x = xx;y = yy;vis[x][y] = 1;
				}
			}
			else{
				d = (d + 1)%4;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
