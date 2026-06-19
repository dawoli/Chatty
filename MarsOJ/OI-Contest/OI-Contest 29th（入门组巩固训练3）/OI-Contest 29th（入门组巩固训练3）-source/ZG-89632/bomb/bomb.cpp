#include <cstdio>
#include <utility>
#include <cstring>
#define PIII pair<int,pair<int,int>>
#define p(a,b,c) make_pair(a,make_pair(b,c))
using namespace std;
const int N=1001;
const int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int n,m,dist[N][N];
char map[N][N];
PIII q[N*N*N];
inline int bfs(int mid){
	memset(dist,255,sizeof(dist));
	int front=1,rear=0;
	q[++rear]=p(mid,1,1);
	dist[1][1]=0;
	while(front<=rear){
		int fire=q[front].first;
		int x=q[front].second.first,y=q[front++].second.second;
		if(x==n&&y==m)return dist[x][y];
		for(int i=0;i<4;i++){
			int nx=x+d[i][0],ny=y+d[i][1];
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(dist[nx][ny]==-1&&map[nx][ny]!='*'){
				if(map[nx][ny]=='$'){
					if(fire)fire--;
					else continue;	
				}
				dist[nx][ny]=dist[x][y]+1;
				q[++rear]=p(fire,nx,ny);	
			}
		}
	}
	return false;
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",map[i]+1);
		int l=0,r=n*m,best=-1,step=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int ret=bfs(mid);
			if(ret){
				r=mid-1;
				best=mid;
				step=ret;
			}else l=mid+1;
		}
		printf("%d %d\n",best,step);
	}
	return 0;
}
