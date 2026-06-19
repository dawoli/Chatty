#include<bits/stdc++.h>
using namespace std;
int n,m,k,x_0,y_0,d_0;
char s[1010][1010];
bool vis[1010][1010];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void scan(){
	scanf("%d%d%d%d%d%d",&n,&m,&k,&x_0,&y_0,&d_0);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	memset(vis,0,sizeof vis);
}
void find(){
	int x=x_0,y=y_0,d=d_0,cnt=0;
	vis[x][y]=1;
	for(int i=1;i<=k;++i){
		int xx=x+dx[d],yy=y+dy[d];
		if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]=='x'){
			d=(d+1)%4;
			continue;
		}
		vis[xx][yy]=1;
		x=xx,y=yy;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cnt+=vis[i][j];
		}
	}
	printf("%d\n",cnt);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scan();
		find();
	}
	return 0;
}
