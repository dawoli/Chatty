#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans=1;
char c[1005][1005];
bool visited[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n >> m >> k >> x >> y >> d;
		for(int j=1;j<=n;j++){
			for(int k1=1;k1<=m;k1++){
				cin >> c[j][k1];
				visited[j][k1]=0;
			}
		}
		for(int j=0;j<k;j++){
			if(d==0&&y+1<=m&&c[x][y+1]=='.'){
				y++;
				if(visited[x][y]==0){
					ans++;
					visited[x][y]=1;
				}
			}else if(d==1&&x+1<=n&&c[x+1][y]=='.'){
				x++;
				if(visited[x][y]==0){
					ans++;
					visited[x][y]=1;
				}
			}else if(d==2&&y-1>=1&&c[x][y-1]=='.'){
				y--;
				if(visited[x][y]==0){
					ans++;
					visited[x][y]=1;
				}
			}else if(d==3&&x-1>=1&&c[x-1][y]=='.'){
				x--;
				if(visited[x][y]==0){
					ans++;
					visited[x][y]=1;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout << ans << endl;
		ans=1;
	}
	return 0;
} 

