#include<iostream>
#define nx (x+addition[direction][0])
#define ny (y+addition[direction][1])
using namespace std;
int addition[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int inquiry;
	cin>>inquiry;
	int row,col,operation;
	int x,y,direction;
	char tmp;
	int ans;
	while(inquiry--){
		cin>>row>>col>>operation;
		cin>>x>>y>>direction;
		bool map[row][col];
		bool passby[row][col];
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>tmp;
				if(tmp=='.')map[i][j]=true;
				else map[i][j]=false;
				passby[i][j]=false;
			}
		}
		x--;y--;
		while(operation--){
			passby[x][y]=true;
			if(nx>=row||nx<0||ny>=col||ny<0||!map[nx][ny]){
				direction=(direction+1)%4;
			}
			else{
				x=nx;y=ny;
			}
		}
		passby[x][y]=true;
		ans=0;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(passby[i][j])ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

