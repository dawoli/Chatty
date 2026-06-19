#include<bits/stdc++.h>
#define N 1002
#define M 1002
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int T,n,m,k,x,y,d;
char ex[N][M];
bool vst[N][M];
void input(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d",&x,&y,&d);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>ex[i][j];
}
void cd(){
	int nx=x+dx[d],ny=y+dy[d];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&ex[nx][ny]=='.') x=nx,y=ny;
	else d=(d+1)%4;
}
int count(){
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(vst[i][j]) ++ans;
	return ans;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		input();
		vst[x][y]=1;
		for(int i=1;i<=k;++i){
			cd();
			vst[x][y]=1;
		}
		printf("%d\n",count());
		memset(vst,0,sizeof(vst));
	}
	return 0;
}
