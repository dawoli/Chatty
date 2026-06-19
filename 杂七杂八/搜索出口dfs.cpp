#include<iostream>
using namespace std;
int n,m;
int a[31][31];
int dir[8][2]={
	{-1,-1},
	{1,1},
	{-1,1},
	{1,-1},
	{0,-1},
	{1,0},
	{0,1},
	{-1,0}
};
void dfs(int x,int y){
	a[x][y]=1;
	for(int i=0;i<8;i++){
		int new_x=x+dir[i][0];
		int new_y=y+dir[i][1];
		if(new_x>=1&&new_x<=n&&new_y>=1&&new_y<=n&&a[new_x][new_y]!=1){
			dfs(new_x,new_y);
		}
	}
}
int main()
{
    cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;	
} 
