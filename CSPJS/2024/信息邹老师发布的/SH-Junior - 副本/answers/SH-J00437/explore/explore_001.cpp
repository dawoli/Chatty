#include<bits/stdc++.h>
using namespace std;
#define N 1010

int t,n,m,k,x,y,d,ans;
bool Map[N][N];
bool vis[N][N];

int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		ans = 0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i = 1;i <= n;i++){
			string s;
			cin>>s;
			for(int j = 0;j < m;j++){
				if(s[j] == '.'){
					Map[i][j + 1] = true;
				}
				else{
					Map[i][j + 1] = false;
				}
			}
		}
		
		for(int i = 1;i <= k;i++){
			if(!vis[x][y]){
				ans++;
				vis[x][y] = true;
			}
			int nx = x + mx[d];
			int ny = y + my[d];
			if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && Map[nx][ny]){
				x = nx;
				y = ny;
			}
			else{
				d = (d + 1) % 4;
			}
		}
		if(!vis[x][y]){
			ans++;
			vis[x][y] = true;
		}
		printf("%d\n",ans);
	}	
	return 0;
}
