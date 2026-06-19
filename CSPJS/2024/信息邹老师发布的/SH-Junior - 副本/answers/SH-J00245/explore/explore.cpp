#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;
struct node{
	int x,y,d;
};
int t;
int n,m,k;
char mp[1010][1010];
void bfs(int sx,int sy,int sd){
	bool vid[1010][1010]={};
	vid[sx][sy]=1;
	int ans=1;
	node d={sx,sy,sd};
	while (k--){
		if (d.d==0){
			if (d.y+1<=m&&mp[d.x][d.y+1]=='.'){
				if (vid[d.x][d.y+1]==0)ans++; 
				vid[d.x][d.y+1]=1;
				d={d.x,d.y+1,d.d};
			}else{
				d={d.x,d.y,(d.d+1)%4};
			}
		}else if (d.d==1){
			if (d.x+1<=n&&mp[d.x+1][d.y]=='.'){
				if (vid[d.x+1][d.y]==0)ans++; 
				vid[d.x+1][d.y]=1;
				d={d.x+1,d.y,d.d};
			}else{
				d={d.x,d.y,(d.d+1)%4};
			}
		}else if (d.d==2){
			if (d.y-1>0&&mp[d.x][d.y-1]=='.'){
				if (vid[d.x][d.y-1]==0)ans++; 
				vid[d.x][d.y-1]=1;
				d={d.x,d.y-1,d.d};
			}else{
				d={d.x,d.y,(d.d+1)%4};
			}
		}else if (d.d==3){
			if (d.x-1>0&&mp[d.x-1][d.y]=='.'){
				if (vid[d.x-1][d.y]==0)ans++; 
				vid[d.x-1][d.y]=1;
				d={d.x-1,d.y,d.d};
			}else{
				d={d.x,d.y,(d.d+1)%4};
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	int x,y,d;
	while (t--){
		cin>>n>>m>>k>>x>>y>>d;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		bfs(x,y,d);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

