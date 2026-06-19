#include <bits/stdc++.h>
using namespace std;
int myt;
int myn,mym,myk,mycnt,myx,myy,myd;
vector<vector<char>> mya;
vector<vector<bool>> vis;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y){
	if(myk==0){
		return ;
	}
	if(!vis[x][y]){
			mycnt++;
		}
	vis[x][y]=true;
	int nx=x+dx[myd];
	int ny=y+dy[myd];
	myk--;
	if(nx>=0&&ny>=0&&nx<myn&&ny<mym&&mya[nx][ny]=='.'){
		dfs(nx,ny);
		vis[x][y]=false;
	}else{
		myd=(myd+1)%4;
		dfs(x,y);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>myt;
	for(int i=0;i<myt;i++){
		cin>>myn>>mym>>myk;
		cin>>myx>>myy>>myd;
		mya.resize(myn,vector<char>(mym));
		vis.resize(myn,vector<bool>(mym,false));
		vis[myx-1][myy-1]=true;
		for(int i=0;i<myn;i++){
			for(int j=0;j<mym;j++){
				cin>>mya[i][j];
				
			}
		}
		mycnt=1;
		myk++;
		dfs(myx-1,myy-1);
		cout<<mycnt<<endl;
	}
	return 0;
}
 
