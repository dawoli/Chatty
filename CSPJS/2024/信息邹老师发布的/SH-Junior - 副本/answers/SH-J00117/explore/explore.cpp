#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,sx,sy,sd;
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
char map[1005][1005]; 
bool vis[1005][1005];
void fun(int x,int y,int d){
	int cx=x+dir[d][0];
	int cy=y+dir[d][1];
	if(cx>=1 && cx<=n && cy>=1 && cy<=m && map[cx][cy]=='.'){
		if(vis[cx][cy]) fun(cx,cy,d);
		else{
			vis[cx][cy]=true;
			cnt++;
		}
	}
	else fun(x,y,(d+1)%4);	
} 
int main(){
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
				vis[i][j]=false;
			}
		}
		int cnt=0;
		fun(sx,sy,sd);
		cout<<cnt;
	}
	return 0;
}
