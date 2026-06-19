#include <iostream>
using namespace std;

int n,m,k,cnt,ans;
int sx,sy,sd;
char mp[1005][1005];
bool vis[1005][1005];

void dfs(int x,int y,int d){
	if(cnt>k) return;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int nd=(d+i)%4;
		int nx,ny;
		cnt++;
		if(nd==0){
			nx=x,ny=y+1;
		}else if(nd==1){
			nx=x+1,ny=y;
		}else if(nd==2){
			nx=x,ny=y-1;
		}else if(nd==3){
			nx=x-1,ny=y;
		}
//		cout << nx <<' '<< ny << endl;
		if(
			nx>=1&&nx<=n &&
			ny>=1&&ny<=m &&
			mp[nx][ny]!='x'
		){
			dfs(nx,ny,nd);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cin >> sx >> sy >> sd;
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&mp[i][j]);
			}
			getchar();
		}
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%c",mp[i][j]);
			}
			printf("\n");
		}
		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
		cnt=0;
		ans=0;
		dfs(sx,sy,sd);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
