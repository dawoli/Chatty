#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct zuoti{
	int x;
	int y;
}que[1000005];
char mp[1005][1005];
int step[1005][1005];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool vis[1005][1005];
int n,m;
int front=0,rear=0;
void bfs(int xx,int yy){
	vis[xx][yy]=1;
	que[rear].x=xx;
	que[rear++].y=yy;
	while(front<rear){
		int pointx=que[front].x,pointy=que[front].y;
		front++;
		for(int i=0;i<=3;i++){
			int nx=pointx+dx[i],ny=pointy+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
				if(mp[nx][ny]=='.'&&vis[nx][ny]==0){
					step[nx][ny]=step[pointx][pointy]+1;
					que[rear].x=nx;
					que[rear++].y=ny;
					vis[nx][ny]=1;
				}
			}
		}
	}
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.in","w",stdout);
	int t;cin >> t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(step,0,sizeof(step));
		front=0;rear=0;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> mp[i][j];
			}
		}
		step[1][1]=0;
		bfs(1,1);
		cout << "0 " << step[n][m] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
