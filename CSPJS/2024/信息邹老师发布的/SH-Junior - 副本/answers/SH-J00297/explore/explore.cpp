#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
char mp[N][N];
bool vst[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T; cin>>T;
	while(T--){
		memset(vst,0,sizeof(vst));
		int n,m,temp; cin>>n>>m>>temp;
		int x,y,dir; cin>>x>>y>>dir;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vst[x][y]=1;
		while(temp--){
			int nx,ny;
			if(dir==0){
				nx=x; ny=y+1;
			}
			else if(dir==1){
				nx=x+1; ny=y;
			}
			else if(dir==2){
				nx=x; ny=y-1;
			}
			else if(dir==3){
				nx=x-1; ny=y;
			}
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.') x=nx,y=ny,vst[x][y]=1;
			else dir=(dir+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt+=vst[i][j];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
