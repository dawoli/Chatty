#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,nowx,nowy,nowd,d,ret,vis[1010][1010];
string s[1010];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t --> 0){
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		x--,y--;
		vis[x][y]=1;
		ret=1,nowx=x,nowy=y,nowd=d;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}for(int i=1;i<=k;i++){
			int xx=nowx+dx[nowd],yy=nowy+dy[nowd];
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]=='.'){
				if(vis[xx][yy]==0){
					ret++;
					//printf("2 ");
				}vis[xx][yy]=1;
				nowx=xx,nowy=yy;
			}else{
				nowd=(nowd+1)%4;
//				for(int i=1;i<4;i++){
//					nowd=(nowd+1)%4;
//					xx=nowx+dx[nowd],yy=nowy+dy[nowd];
//					if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]=='.'){
//						if(vis[xx][yy]==0){
//							ret++;
//						}vis[xx][yy]=1;
//						nowx=xx,nowy=yy;
//						break;
//					}
//				}
			}//printf("%d %d %d\n",nowx+1,nowy+1,nowd);
		}printf("%d\n",ret);
	}return 0;
}
