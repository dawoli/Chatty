#include<iostream>
#include<cstdio>
using namespace std;
const int N=1010;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int t,n,m,k,x,y,d,c,nx,ny;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		c=1;
		char s[N][N]={};
		bool vis[N][N]={};
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		vis[x][y]=1;
		for(int i=0;i<k;i++){
			nx=x+dir[d][0],ny=y+dir[d][1];
			if(nx>n||nx<1||ny>m||ny<1
				||s[nx][ny]=='x'){
				d=(d+1)%4;
			}
			else{
				x=nx,y=ny;
				if(!vis[x][y]){
					c++;
					vis[x][y]=1;
				}
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
