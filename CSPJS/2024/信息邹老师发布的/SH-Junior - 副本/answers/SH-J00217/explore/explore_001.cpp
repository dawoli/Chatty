#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t; 
	cin>>t;
	while(t--){
		bool board[1005][1005];
		memset(board,true,sizeof(board));
		int startx,starty,face; 
		int n,m,k;
		bool vis[1005][1005];
		memset(vis,false,sizeof(vis));
		cin>>n>>m>>k;
		cin>>startx>>starty>>face;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char ch;
				cin>>ch;
				if(ch=='.'){
					board[i][j]=false;
				}else if(ch=='x'){
					board[i][j]=true;
				}
			}
		}//棋盘数据构建 
		vis[startx][starty]=1; //标记出生点
		for(int i=1;i<=k;i++){
			int nextPointx=startx,nextPointy=starty;
			if(face==0){
				nextPointy++;
			}else if(face==1){
				nextPointx++;
			}else if(face==2){
				nextPointy--;
			}else if(face==3){
				nextPointx--;
			}
//			cout<<i<<' '<<nextPointx<<' '<<nextPointy<<' '<<face<<' '<<board[nextPointx][nextPointy]<<' '<<endl; 
			if(board[nextPointx][nextPointy]==false){
				vis[nextPointx][nextPointy]=true;
				startx=nextPointx;starty=nextPointy;//跟新点位 
			}else{
				face=(face+1)%4;//向右转 
			}
		} 
		long long c=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					c++;
				}
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 

