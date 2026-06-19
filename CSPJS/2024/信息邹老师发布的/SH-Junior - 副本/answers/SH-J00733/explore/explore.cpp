#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int nextx[4] = {0,1,0,-1};
const int nexty[4] = {1,0,-1,0};
bool a[1010][1010];
bool vis[1010][1010];

void to_start(){
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    return;
}

void dfs(int x,int y,int d,int cur){
	vis[x][y] = 1;
	/*for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i!=x||j!=y)printf("%d",a[i][j]);
			else printf("#");
		}
		printf("\n");
	}
	Sleep(1000);
	system("cls");*/
    if(cur > k) return;
	int nx = x+nextx[d],ny = y+nexty[d];
    if(nx < 1||nx > n||ny < 1||ny > m||!a[nx][ny]){
        dfs(x,y,(d+1)%4,cur+1);
        return;
	}

    dfs(x+nextx[d],y+nexty[d],d,cur+1);
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    scanf("%d",&t);
    
    while(t--){
        to_start();
        int sx,sy,sd;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&sx,&sy,&sd);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                char c;
                cin >> c;
                if(c == '.') a[i][j] = 1;
            }
        }
        dfs(sx,sy,sd,1);
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cnt+=vis[i][j];
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
