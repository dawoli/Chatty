#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T,n,m,k;
const int N=1005;
char map_[N][N];
bool vis[N][N];
int sx,sy,d,nx,ny,cnt;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(map_ ,0 , sizeof(map_) );
		memset(vis ,0 , sizeof(vis) );
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		nx=sx;
		ny=sy;
		cnt=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>map_[i][j];
		vis[sx][sy]=1;
		for(int i=1;i<=k;i++){
			if(d==0) 		ny++;
			else if(d==1) nx++;
			else if(d==2) ny--;
			else 		nx--;
			
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && map_[nx][ny] == '.') vis[nx][ny]=1;
			else{//回溯 
				if(d==0) 		ny--;
				else if(d==1) nx--;
				else if(d==2) ny++;
				else 			nx++;
				d=(d+1)%4;//改变方向 
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]) cnt++;
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
