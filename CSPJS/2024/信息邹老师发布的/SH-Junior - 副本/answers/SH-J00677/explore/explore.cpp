#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int t,m,n,sx,sy,sd,ans,g;char c[maxn][maxn];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[maxn][maxn];
inline bool valid(int x,int y){
	if(c[x][y]=='x') return false;
	return -1<x&&x<n&&-1<y&&y<m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		memset(vis,0,sizeof(vis));ans=1;
		scanf("%d %d %d",&n,&m,&g);
		scanf("%d %d %d",&sx,&sy,&sd);
		sx--;sy--;vis[sx][sy]=true;
		for(int j=0;j<n;j++){
			scanf("%s",c[j]);
		}
		while(g>0){
			while(!valid(sx+dx[sd],sy+dy[sd])){
				sd=(sd+1)%4;g--;
				if(g==0) break;
 			}
 			if(g==0) break;
 			while(valid(sx+dx[sd],sy+dy[sd])){
				g--;
				if(!vis[sx+dx[sd]][sy+dy[sd]]){
					vis[sx+dx[sd]][sy+dy[sd]]=true;ans++;
				}
				sx+=dx[sd];sy+=dy[sd];
				if(g==0) break;
 			}
 			if(g==0) break;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
